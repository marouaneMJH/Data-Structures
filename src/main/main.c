#include <stdio.h>
#include "./../../include/common/DataStructur.h"

int main() {
    // Create a new linked list header
    nodeHeader* list = createNodeHeader();

    // Add elements to the linked list
    addInLast(list, 10);
    addInLast(list, 20);
    addInLast(list, 30);
    addInFirst(list, 5);
    addByPosition(list, 25, 3);

    // Display the elements of the linked list
    printf("Linked list elements: ");
    node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Remove elements from the linked list
    removeHead(list);
    removeLast(list);

    // Display the elements of the linked list after removal
    printf("Linked list elements after removal: ");
    current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the memory allocated for the linked list
    removeLinkedList(list);

    return 0;
}
