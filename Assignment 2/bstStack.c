#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------*/
/*CODE BELOW IS IN REFERENCE TO LECTURE 4 WITH IMPLEMENTATION OF A PTR STACK INSTEAD*/
/*----------------------------------------------------------------------------------*/
#define BADVAL -9999
struct node1 {
    struct node * info;//ptr to node of BST
    struct node1* next;
};

typedef struct node1* NODEPTR;

NODEPTR createNode1(struct node* elm) {
    NODEPTR temp = (NODEPTR)malloc(sizeof(struct node1));//PTR TO bst NODE
    temp->info = elm;
    temp->next = NULL;
    return temp;
}

int isEmpty1(NODEPTR p) {
    if (p == NULL)
        return 1;
    else
        return 0;
}

struct node* pop(NODEPTR* ap) {
    NODEPTR temp;
    struct node* val;
    if (isEmpty1(*ap))
        return NULL;
    else {
        temp = *ap;
        (*ap) = (*ap)->next;
        val = temp->info;
        free(temp);
        return val;//The value returned would be address
    }
}

void push(NODEPTR* ap, struct node* elm) {
    NODEPTR temp;
    temp = createNode1(elm);//pust a pointer of the BST node
    if (*ap == NULL)
        *ap = temp;
    else {
        temp->next = *ap;
        *ap = temp;
    }
}
/*----------------------------------------------------------------------------------*/
/*BELOW CODE IS IMPLEMENTATION OF  BINARY SEARCH TREE*/
/*----------------------------------------------------------------------------------*/
struct node{// creating a structure for a node of a bst
    int key;
    struct node *left, *right;
};

void displayNode(struct node *temp){
    if (temp == NULL)
        printf("Node does not exist\n");
    else
        printf("%x %d\n", (unsigned int) temp, temp->key);//displaying the node address and key value
}

struct node * createNode(int k){// creates a node with key value k
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));//allocating memory space
    temp->key = k;
    temp->left = temp->right = NULL;// setting null value to the ptr to children
    return temp;// returing the newly created node
}

struct node * search(struct node * anode, int k){//the root node and key value are accepted
    struct node *temp, *parent;
    if (anode == NULL) return NULL;
    temp = anode;//setting ptr to the root
    while (temp != NULL){
        if (temp->key == k){
            return temp;//element is found
        }
        if (k < temp->key){//checking to decide tree traversal
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return NULL;
}
struct node * insert(struct node * anode, int k){// the same as given by prof during class
    struct node *temp, *parent;
    int direction;
    if (anode == NULL){
        anode = createNode(k);
    return anode;
    }
    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            printf("node with value %d exists\n", k);
        return temp;
        }
        if (k < temp->key){
            parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
            parent = temp;
            temp = temp->right;
            direction = 1;
        }
    }

    temp = createNode(k);
    if (direction == 0)
        parent->left = temp;
    else
        parent->right = temp;
    return temp;
}
/*CODE CHANGES MADE TO IMPLEMENT LINKED LIST STACK FOR ITERATIVE INORDER*/
void inorder(struct node * anode){
    NODEPTR s = NULL;// ptr to the stack that is empty
    struct node* current = anode;//a ptr to the root
    
    while ((current != NULL) || (!isEmpty1(s))) {//check if the lowest left child
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);

        printf("%d ",current->key);
        if (current != NULL) {
            current = current->right;
        }
    }
}
/*==============================================================================*/

int main()
{
    struct node * root = NULL, *temp;
    int elm, menu;
    while(1){
        printf("0. exit, 1. initialize, 2. search, 3. insert, 4. inorder. Input Choice: ");
        scanf("%d", &menu);
        switch(menu){
            case 0: exit(0);
            case 1: root = NULL;
            break;
            case 2: printf("Give element to search: ");
                scanf("%d", &elm);
                temp = search(root, elm);
                displayNode(temp);
            break;
            case 3: printf("Give element to insert: ");
                scanf("%d", &elm);
                if (root == NULL)
                temp = root = insert(root, elm);
                else
                temp = insert(root, elm);
                displayNode(temp);
                break;
            case 4: inorder(root);
                printf("\n");
            break;
            default: printf("Wrong choice\n");
        }
    }
    return 0;
}