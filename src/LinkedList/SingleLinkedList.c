#include "./../../include/common/DataStructur.h"





node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode== NULL)
        return NULL;
    
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

nodeHeader* createNodeHeader(){
    nodeHeader* newNodeHeader=(nodeHeader*)malloc(sizeof(nodeHeader));
    if(newNodeHeader == NULL)
        return NULL;
    
    newNodeHeader->head=NULL;
    newNodeHeader->last=NULL;
    newNodeHeader->size=0;
    return newNodeHeader;
}

int addInLast(nodeHeader* nodeHeader, int data){

    node* newElement = createNode(data);

    if( newElement == NULL)
        return 0;
    
    if(nodeHeader->size == 0 ){
    
        nodeHeader->head=newElement;
        nodeHeader->last=newElement;
        nodeHeader->size++;
    
        return 1;
    }

    nodeHeader->last->next= newElement;   
    nodeHeader->last=newElement;
    nodeHeader->size++;

    return 1;

}

int addInFirst(nodeHeader* nodeHeader, int data){

    node* newElement=createNode(data);

    if( newElement == NULL)
        return 0;
    
    if(nodeHeader->size == 0 ){
    
        nodeHeader->head=newElement;
        nodeHeader->last=newElement;
        nodeHeader->size++;
    
        return 1;
    }

    newElement->next=nodeHeader->head;
    nodeHeader->head=newElement;
    nodeHeader->size++;

    return 1;

}

int addByPosition(nodeHeader* nodeHeader, int data, int postion){

    node* newElement=createNode(data);
    node* curent=nodeHeader->head;

    if(postion > nodeHeader->size || postion < 1 )
        return 0;

    if(postion == 1)
        return addInFirst(nodeHeader,data);

    if(postion == nodeHeader->size)
        return addInLast(nodeHeader,data);
    
    for(int i=1;i<postion-1;i++)
        curent = curent->next;

    newElement->next=curent->next;
    curent->next=newElement;
    nodeHeader->size++;
    
    return 1;
}


int removeLinkedList(nodeHeader* nodeHeader){
    
    while( nodeHeader->head != NULL){
        node* temp = nodeHeader->head;
        nodeHeader->head = nodeHeader->head->next;
        free(temp);
    }

    free(nodeHeader);

    return 1;
}


int removeHead(nodeHeader* nodeHeader){

    if(nodeHeader->size == 0)
        return 0;
    
    if(nodeHeader->size == 1){
        return removeLinkedList(nodeHeader);
    }
    
    nodeHeader->head= nodeHeader->head->next;
    nodeHeader->size--;

    return 1;

}

int removeLast(nodeHeader* nodeHeader){
    
    if( nodeHeader == NULL || nodeHeader->size == 0 )
        return 0;

    if(nodeHeader->size == 1){
        return removeLinkedList(nodeHeader);
    }


    node* curent;
    node* temp;
    curent = nodeHeader->head;



    for(int i=0;i<nodeHeader->size;i++){
        
        if(i == nodeHeader->size-2){

            curent->next=NULL;
            nodeHeader->size--;

            temp = nodeHeader->last;
            nodeHeader->last=curent;

            free(temp);

            return 1;
        }

        curent=curent->next;
    }
}


nodeHeader *fillLikedList(int size){
    nodeHeader* returnedList;
    returnedList=createNodeHeader();

    

    for(int i=0;i<size;i++){    
        int temp=rand()%100;

        addInFirst(returnedList, temp);
    }

    return returnedList;
}



void printList(nodeHeader* nodeHeader){
    
    node* curent=nodeHeader->head;


    while (curent!=NULL){
        printf(" %d -->",curent->data);
        curent=curent->next;
    }

    printf(" NULL\n");
}



