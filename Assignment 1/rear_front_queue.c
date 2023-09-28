#include <stdio.h>
#include <stdlib.h>
#define BADVAL -9999
struct node{ // defining the structure of a node in a linked list
    int info;// value at the node
    struct node *next;// pointer to address of the next node
};
typedef struct node * NODEPTR; //NODEPTR points to address of a node
typedef struct queue{//defining a structure QUEUE on a linked list
    NODEPTR front, rear; //only need a pointer to the front and end of linked list
} QUEUE;

NODEPTR createNode(int val){//creating a new node given a value
    NODEPTR p;//creating a pointer to an address
    p = (NODEPTR) malloc(sizeof(struct node));//memory allocating space of size (struct node) at address pointed by NODEPTR
    p->info = val;// storing info/value part
    p->next = NULL;// the address bit, the new node points to NULL as its the last entry
    return p;// retur the newly created node
}
int delete(QUEUE *q){// deleting a node
    NODEPTR temp;// for swap
    int val;
    if (q->front == NULL) return BADVAL;// check if linked list is empty
    else{
        temp = q->front;//setting temp to the front node
        q->front = q->front->next;//changing the first node to next node 
        val = temp->info;//value of the popped element
        free(temp);// freeing the space allocated to the first node
        if (q->front == NULL)//if new front of queue is null then that should mean
            q->rear = NULL;//rear is also NULL, no element in queue
        return val;//return value of the popped element
    }
}
void insert(QUEUE *q, int elm){// given a ptr to a q adding an element
    NODEPTR temp;//node pointer to an address
    temp = createNode(elm);// function call to create  a temporary node with temp->info = elm
    if (q->front == NULL){//check if queue is empty
        q->front = temp;//the new node is at the front of the queue
        q->rear = temp;//the end of the queue is also this new node, there is only one node
    }
    else{
        (q->rear)->next = temp;//addind the node to the end of the the linked list
        q->rear = temp;//setting the new node as the end of the queue
    }
}
void printQueue(QUEUE *q){//printing a queue given pointer
    NODEPTR temp;//creating a temporary pointer
    if (q->front == NULL){//check if queue is empty
        printf("Queue empty\n");
        return;
    }
    printf("F ->");// if not print F-> i.e. front
    for (temp = q->front; temp!= NULL; temp = temp->next)//traversing to end of linked list
        printf("%d ", temp->info);//printing the value/info of each node in the queue
    printf("<- R\n");//when end is reached i.e. rear
}
int main(){
    QUEUE q1;// creating a variable queue q1
    int elm, menu;// declaring integers elm and menu 
    while(1){// continue while true
        printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
        scanf("%d", &menu);//scanning and storing the menu option chosen
        switch(menu){
            case 0: exit(0);// exit  when menu=0
            case 1: q1.front =q1.rear = NULL;//initializing the queue
            break;
            case 2: printf("Popped Value %d\n", delete(&q1));//deleting an element by calling function
            break;
            case 3: printf("Give element: ");//adding an element
            scanf("%d", &elm);//saving the new info part for rear node of the queue in elm
            insert(&q1, elm);//calling insert function to insert at rear
            break;
            case 4: printQueue(&q1);//printing the queue
            break;
            default: printf("Wrong choice\n");//when option chosen doesnt exist in list
}
}
}