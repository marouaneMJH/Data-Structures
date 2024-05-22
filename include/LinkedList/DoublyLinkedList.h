#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct nodeDoubly{

    int data;
    struct nodeDoubly *next;
    struct nodeDoubly  *prev;

}nodeDoubly;

typedef struct nodeDoublyList
{
    int size;
    struct nodeDoubly *head;
    struct nodeDoubly *last;

}nodeDoublyList;

/**
 * @brief for creating a doubly node  
 * @param data is the of created doubly node
 * @return nodeDoubly   
*/
nodeDoubly* createDoublyNode(int data);



/**
 * @brief for creating a doubly linked list  
 * @return nodeDoublyList   
*/
nodeDoublyList* createDoublyLinkedList();

bool addInFirstDoubly(nodeDoublyList* list, int data);

bool addInLastDoubly(nodeDoublyList* list, int data);

nodeDoublyList* fillDoublyLinkedList(int size);

void printDoublyLinkedList(nodeDoublyList* list);


nodeDoublyList* reverseDoublyLinkedList(nodeDoublyList* list);

#endif
