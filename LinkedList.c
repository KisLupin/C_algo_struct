#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 

void push(struct Node** head, int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
    *head = node;
}

void append(struct Node** head, int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head;
    new_node->data  = data; 
    new_node->next = NULL; 
    if (*head == NULL) { 
       *head = new_node; 
       return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
}

void printList(struct Node *node) 
{ 
  while (node != NULL) { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
} 

void insertAfter(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
} 

void deleteNode(struct Node **head, int key) 
{ 
    struct Node* temp = *head, *prev; 
    if (temp != NULL && temp->data == key) { 
        *head = temp->next;   
        free(temp);      
        return; 
    } 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp); 
} 

int main() 
{ 
  struct Node* head = NULL; 
  push(&head, 1); 
  push(&head, 2); 
  push(&head, 3); 
  push(&head, 4); 
  deleteNode(&head, 3);
  printf("\n Created Linked list is: "); 
  printList(head); 

  return 0; 
} 