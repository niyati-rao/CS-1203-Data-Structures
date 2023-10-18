/*AVL TREE CODE LABELLED AS avl1.c in google classroom 
  Modified part of code is mentioned with ============*/
#include <stdio.h>  
#include <stdlib.h>  
   
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
   
int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  
   
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    // Process right child first
    displayTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    displayTree(root->left, space);
}
   
int max (int a, int b){  
    return (a>b)?a:b;  
}  
   
int getBalanceFactor(struct Node * n){  
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  
   
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  
   
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  
}  
   
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  
   
    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case  
        if(bf>1 && key < node->left->key){  
            return rightRotate(node);  
        }  
    // Right Right Case  
        if(bf<-1 && key > node->right->key){  
            return leftRotate(node);  
        }  
    // Left Right Case  
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
    // Right Left Case  
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    return node;  
} 
//===========================EDITED FRAGMENT========================
//resource used: geeks for geeks
//traversing to the node with minimum value
struct Node *findMin(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;//traversal to the lefmost leaf node
    return current;
}
//deletion code:
struct Node *deleteNode(struct Node *node, int key)
{
    if (node == NULL)
        return node;
    //----------------------------------------------------------------
    // deletion done by first deleting as in a BST
    //by first traversing through the tree recursively
    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else //when key value is found
    {
        //one child or no child
        if ((node->left == NULL)||(node->right == NULL))
        {
            struct Node *temp;
            if (node->left)
            {
                temp = node->left;
            } 
            else
            {
                temp = node->right;
            }
            //no child replacing the node with NULL
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);  //as the node is deleted free space
        }
        //with two children
        else
        {
            //in-order successor which is found using the function finfMin()
            struct Node *temp = findMin(node->right);
            node->key = temp->key; // make successor the new key of node
            node->right = deleteNode(node->right, temp->key);//delete successor from previous position
        }
    }
    //--------------------------------------------------------------------------------------------

    if (node == NULL)//check if tree has only one node
        return node;

    // Updating heigh and and balace factor to make necessary rotations to restore balance
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
    
    //similar to insertion balancing 
    // Left Left Case
    if (bf > 1 && getBalanceFactor(node->left) >=0)
        return rightRotate(node);

    // Left Right Case
    if (bf > 1 && getBalanceFactor(node->left) <0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && getBalanceFactor(node->right) <=0)
        return leftRotate(node);

    // Right Left Case
    if (bf < -1 && getBalanceFactor(node->right) >0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//==================================================================
   
void preOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        preOrder(root->left);  
        printf("%d ", root->key);  
        preOrder(root->right);  
    }  
}  
   
int main(){  
    struct Node * root = NULL;  
   
   
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 60);  
    root = insert(root, 30);  
    root = insert(root, 70);  
    root = insert(root, 80);  
    root = insert(root, 90);  
    preOrder(root);  
    printf("\n");

    inOrder(root);  
    printf("\n");

    displayTree(root, 10);

//===================DISPLAY DELETION=============================
    int delKey = 30;
    root = deleteNode(root, delKey);

    printf("After deleting %d:\n", delKey);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    displayTree(root, 10);
//=================================================================

    return 0;  
}  
