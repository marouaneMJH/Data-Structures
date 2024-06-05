#include "./../../include/common/DataStructur.h"


nodeDoubly* createDoublyNode(int data){

    nodeDoubly* newNode = (nodeDoubly*)malloc(sizeof(nodeDoubly));

    if (newNode==NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

nodeDoublyList* createDoublyLinkedList(){

    nodeDoublyList* newNodeDoublyLinkedList=(nodeDoublyList*)malloc(sizeof(nodeDoublyList));

    if(newNodeDoublyLinkedList==NULL)
        return NULL;

    newNodeDoublyLinkedList->head=NULL;
    newNodeDoublyLinkedList->last=NULL;
    newNodeDoublyLinkedList->size=0;

    return newNodeDoublyLinkedList;

}


// adding functions

bool addInFirstDoubly(nodeDoublyList* list, int data){

    nodeDoubly* newNode = createDoublyNode(data);
    
    if(newNode==NULL){
        printf("problem in adding %d item\n", data);
        return false;
    }

    if(list->size==0){
        
        list->head=newNode;
        list->last=newNode;
        list->size++;

        return true;
    }

    newNode->next=list->head;
    list->head->prev=newNode;
    list->head=newNode;
    list->size++;
    
    return true;
}

bool addInLastDoubly(nodeDoublyList* list, int data){
    
    nodeDoubly* newNode = createDoublyNode(data);
    
    if(newNode==NULL){
        printf("problem in adding %d item\n", data);
        return false;
    }

    if(list->size==0)
        return addInFirstDoubly(list,data);
    
    list->last->next=newNode;
    newNode->prev=list->last;
    list->last=newNode;
    list->size++;

    return true;
}


//deleting functions

int deleteHeadDoubly(nodeDoublyList* list){

    if(doublyIsEmpty(list)){
        printf("\nThe doubly List is empty");
    }

    nodeDoubly* curent;

}

//Search and Access

bool doublyIsEmpty(nodeDoublyList* list){
    return list->size==0;
}

int getDoublySize(nodeDoublyList* list){
    return list->size;
}

nodeDoubly* getHead(nodeDoublyList* list){
    return list->head;
}

nodeDoubly* getLast(nodeDoublyList* list){
    return list->last;
}

int doublyFind(nodeDoublyList* list, int value){
    
    nodeDoubly* curent= list->head;

    for(int i=0;i<list->size;i++){
        if(curent->data==value)
            return i+1;

        curent=curent->next;
    }

    return -1;
}


nodeDoubly* getDoublyNodeAt(nodeDoublyList* list,int position){

    
    nodeDoubly* curent=list->head;

    for(int i=1;i<position;i++){
        curent=curent->next;
    }

    return curent;
}



nodeDoublyList* fillDoublyLinkedList(int size){
    srand(time(NULL));

    nodeDoublyList* list=createDoublyLinkedList();
    int random;

    for(int i=0;i<size;i++){
        random=rand()%size;
        
        if(!addInLastDoubly(list,random)){
            printf("problem in Fill list");
            return NULL;
        }
    }

    return list;

}



void printDoublyLinkedList(nodeDoublyList* list){

    if(list==NULL)
        printf("NULL");
    
    nodeDoubly* temp = list->head;

    while (temp!=NULL)
    {
        printf("%d --> ", temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
    
}


nodeDoublyList* reverseDoublyLinkedList(nodeDoublyList* list){
    
    if(list==NULL)
        return NULL;
    
    nodeDoubly* curent=list->last;

    nodeDoublyList *returnedList = createDoublyLinkedList();    

    while(curent != NULL){

        if(addInLastDoubly(returnedList,curent->data)==false){
            printf("error in adding.");
            return NULL;
        }

        curent=curent->prev;
    }

    return returnedList;
}



