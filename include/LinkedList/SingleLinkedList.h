#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

typedef struct node
{
    int data;
    struct node *next;

}node;

typedef struct  nodeHeader{
    
    int size;
    node *head;
    node *last;
    
}nodeHeader;

/**
 * @brief create  a linked list 
 * @return pointer of nodeHeader 
*/
nodeHeader *createNodeHeader();

/**
 *@brief creat a node element
 *@param int data 
 *@return pointer of node 
*/
node *createNode(int data);

/**
 * @brief add element to existed linked list 
 * @param nodeHeader existed linked list 
 * @param int data
 * @return bool variable that show the  adding success or not  
*/
int addInLast(nodeHeader* nodeHeader, int data);

int addInFirst(nodeHeader* nodeHeader, int data);

int addByPosition(nodeHeader* nodeHeader, int data, int postion);


int removeLinkedList(nodeHeader* nodeHeader);

int removeHead(nodeHeader* nodeHeader);

int removeLast(nodeHeader* nodeHeader);

// int removeByPosition(nodeHeader* nodeHeader, int postion);

// void printLinkedList(nodeHeader* nodeHeader);

#endif


