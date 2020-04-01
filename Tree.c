#include <stdio.h> 
#include <stdlib.h> 
int temp = 0;
struct Node { 
    int data; 
    struct Node* right; 
    struct Node* left; 
};

struct Node* newNode(int data){
   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}

void insert(struct Node** tree, int val) {
    struct Node *temp = NULL;
    if(!(*tree)) {
        *tree = newNode(val);
        return;
        }
    if(val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->data) {
        insert(&(*tree)->right, val);
   }
}

int maxDepth(struct Node* root)
{
  // Root being null means tree doesn't exist.
  if (root == NULL)
    return 0;
  
  // Get the depth of the left and right subtree 
  // using recursion.
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  // Choose the larger one and add the root to it.
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}

void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
} 
void print_postorder(struct Node * tree) {
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->data);
    }
}
void print_preorder(struct Node * tree) {
    if (tree) {
        printf("%d ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
     }
}

int count(struct Node* tree){
    if (tree) {
        temp++;
        count(tree->left);
        count(tree->right);
    }
    return temp;
}

struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct Node* deleteNode(struct Node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct Node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main(int argc, char const *argv[])
{
    struct Node* root = newNode(30);
    struct Node* searched = NULL;
    insert(&root,25);
    insert(&root,22);
    insert(&root,46);
    insert(&root,37);
    insert(&root,13);
    insert(&root,60);
    insert(&root,50);
    insert(&root,34);
    insert(&root,80);
    root = deleteNode(root, 22);
    printf("Inorder\n");
    printInorder(root);
    printf("\nPostOrder\n");
    print_postorder(root);
    printf("\nPreOrder\n");
    print_preorder(root);
    printf("\nmax depth: %d", maxDepth(root));
    printf("\ncount: %d", count(root));
    return 0;
}

