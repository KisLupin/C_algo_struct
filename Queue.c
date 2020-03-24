#include <stdio.h> 
#include <stdlib.h> 

struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 

int isFull(struct Queue* queue)  
{ return (queue->size == queue->capacity); }  
  
// Queue is empty when size is 0  
int isEmpty(struct Queue* queue)  
{ return (queue->size == 0); }  

void enQueue(struct Queue* queue, int n){
    if (isFull(queue)){
       return;
    }
    queue->rear = (queue->rear +1)%queue->capacity;
    queue->size = queue->size+1;
    queue->array[queue->rear] = n;
}
int deQueue(struct Queue* queue){
    if(isEmpty(queue)){
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front += 1;
    queue->size = (queue->size -1) % queue->capacity;
    return item;
}

int front(struct Queue* queue)  
{  
    if (isEmpty(queue))  
        return -1;  
    return queue->array[queue->front];  
}  
  
// Function to get rear of queue  
int rear(struct Queue* queue)  
{  
    if (isEmpty(queue))  
        return -1;  
    return queue->array[queue->rear];  
}  
  
int main()  
{  
    struct Queue* queue = createQueue(1000);  
  
    enQueue(queue, 100);  
    enQueue(queue, 20);  
    enQueue(queue, 30);  
    enQueue(queue, 40);  

    printf("%d\n",front(queue));
    printf("%d\n",deQueue(queue));
    printf("%d\n",rear(queue));
    return 0;  
}  
  