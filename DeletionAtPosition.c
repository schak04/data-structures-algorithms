#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void deleteNodeAtGivenPos(struct Node** head_ref, int n) {
    //Type your code here
    if (*head_ref == NULL || n <= 0)
        return;

    struct Node* temp = *head_ref;
    int count = 1;

    // Traverse to the node at the given position
    while (temp != NULL && count < n) {
        temp = temp->next;
        count++;
    }

    // If the position is more than the number of nodes
    if (temp == NULL)
        return;

    // Delete the node at the position
    deleteNode(head_ref, temp);
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    int n, data;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&head, data);
    }

    printf("Before deletion: ");
    printList(head);

    int pos;
    scanf("%d", &pos);

    deleteNodeAtGivenPos(&head, pos);

    printf("\nAfter deletion: ");
    printList(head);

    return 0;
}