#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a circular linked list
void insertEnd(struct Node** last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*last == NULL) {
        *last = newNode;
        (*last)->next = *last;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

// Function to delete a node from a circular linked list
void deleteNode(struct Node** last, int key) {
    if (*last == NULL) return;

    struct Node* temp = (*last)->next;
    struct Node* prev = NULL;

    if (((*last)->next == *last) && ((*last)->data == key)) {
        free(*last);
        *last = NULL;
        return;
    }

    do {
        if (temp->data == key) {
            if (prev != NULL) prev->next = temp->next;
            if (temp == *last) *last = prev;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != (*last)->next);
}

// Function to traverse and print the circular linked list
void traverse(struct Node* last) {
    if (last == NULL) return;

    struct Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    struct Node* last = NULL;

    insertEnd(&last, 10);
    insertEnd(&last, 20);
    insertEnd(&last, 30);
    insertEnd(&last, 40);

    printf("List before deletion: ");
    traverse(last);

    deleteNode(&last, 20);
    deleteNode(&last, 40);

    printf("List after deletion: ");
    traverse(last);

    return 0;
}
