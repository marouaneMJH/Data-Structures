#include "./../LinkedList/SingleLinkedList.c"

int main() {


    nodeHeader* list = createNodeHeader();
    
    printf("Adding elements to the end of the list:\n");
    addInLast(list, 10);
    addInLast(list, 20);
    addInLast(list, 30);
    printList(list);  // Expected output: 10 --> 20 --> 30 --> NULL

    printf("\nAdding elements to the beginning of the list:\n");
    addInFirst(list, 5);
    printList(list);  // Expected output: 5 --> 10 --> 20 --> 30 --> NULL

    printf("\nAdding elements by position:\n");
    addByPosition(list, 15, 3);
    printList(list);  // Expected output: 5 --> 10 --> 15 --> 20 --> 30 --> NULL

    printf("\nRemoving the head of the list:\n");
    removeHead(list);
    printList(list);  // Expected output: 10 --> 15 --> 20 --> 30 --> NULL

    printf("\nRemoving the last element of the list:\n");
    removeLast(list);
    printList(list);  // Expected output: 10 --> 15 --> 20 --> NULL

    printf("\nFilling a new list with random elements:\n");
    nodeHeader* filledList = fillLikedList(5);
    printList(filledList);  // Expected output: List with 5 random elements

    printf("\nRemoving all elements from the filled list:\n");
    removeLinkedList(filledList);
    
    return 0;
}


