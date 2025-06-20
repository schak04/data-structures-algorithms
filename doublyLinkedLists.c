#include <stdio.h>
#include <stdlib.h>
/*
Note:
1. During the insertion of a new node at a position
   (other than the beginning and the end),
   always update the prev and next pointers of the new node at first,
   and only then do the rest of the updates (for the surrounding nodes).
   Otherwise, the compiler would go crazy.
2. During the deletion of a node at a position
   (other than the beginning and the end),
   update the pointers of the surrounding nodes at first,
   and then set the pointers of the node to be deleted
   to NULL (C/C++) or nullptr (C++),
   and finally free or delete the node to be deleted.
*/

/* Doubly Linked List */

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void forwardTraversal(struct node* head) {
    struct node* temp = head;
    printf("NULL <-> ");
    while (temp!=NULL) {
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void backwardTraversal(struct node* tail) {
    struct node* temp = tail;
    printf("NULL <-> ");
    while (temp!=NULL) {
        printf("%d <-> ", temp->data);
        temp=temp->prev;
    }
    printf("NULL");
}

struct node* insertAtBeginning(struct node* head, int value) {
    struct node* newNode = createNode(value);
    if (head!=NULL) {
        newNode->next=head;
        head->prev=newNode;
    }
    return newNode;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);

    // if the linked list is empty
    if (head==NULL) {
        head = newNode;
    }
    else {
        struct node* curr = head;
        // traverse until the last node
        while (curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=newNode;
        newNode->prev=curr;
    }
    return head;
}

struct node* deleteAtBeginning(struct node* head) {
    if (head==NULL) {
        return NULL;
    }
    else if (head->next==NULL) {
        free(head);
        return NULL;
    }
    // store in temp for deletion later
    struct node* temp = head;
    // move head to the next node
    head = head->next;
    // set prev of the new head
    head->prev = NULL;
 
    free(temp);
    return head;
}

struct node* deleteAtEnd(struct node* head) {
    if (head==NULL) {
        return NULL;
    }
    if (head->next==NULL) {
        free(head);
        return NULL;
    }
    // traverse to the last node
    struct node* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    // update the prev node's next pointer
    temp->prev->next = NULL;
    // delete the last node
    free(temp);
    return head;
}

struct node* insertAtPosition(struct node* head, int position, int value) {
    if (position==1) {
        return insertAtBeginning(head, value);
    }
    struct node* newNode = createNode(value);
    struct node* current = head;
    for (int i = 1; (i < position-1 && current != NULL); i++) {
        current=current->next;
    }
    if (current==NULL) {
        return head;
    }
    if (current->next!=NULL) {
        newNode->next=current->next;
        newNode->prev=current;
        current->next->prev=newNode;    
        current->next=newNode;
    }
    return head;
}

struct node* deleteAtPosition(struct node* head, int position) {
    if (head==NULL) {
        return NULL;
    }
    if (head->next==NULL) {
        free(head);
        return NULL;
    }
    if (position == 1) {
        return deleteAtBeginning(head);
    }

    struct node* current = head;
    for (int i = 1; (i < position && current != NULL); i++) {
        current=current->next;
    }
    current->prev->next=current->next;
    current->next->prev=current->prev;
    current->next=NULL;
    current->prev=NULL;

    free(current);
    return head;
}

int main() {

    // Unlike in SLL, here we'll create 3 nodes
    struct node* head = createNode(2);
    struct node* second = createNode(6);
    struct node* third = createNode(4);

    // Creation of links
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;

    printf("Forward Traversal of the doubly-linked list: \n");
    forwardTraversal(head);
    printf("\n");
    
    printf("Backward Traversal of the doubly-linked list: \n");
    backwardTraversal(third);
    printf("\n");
    
    head = insertAtBeginning(head, 20);
    printf("After insertion at the beginning: \n");
    forwardTraversal(head);
    printf("\n");
    
    head = insertAtEnd(head, 66);
    printf("After insertion at the end: \n");
    forwardTraversal(head);
    printf("\n");
    
    head = deleteAtBeginning(head);
    printf("After deletion at the beginning: \n");
    forwardTraversal(head);
    printf("\n");
    
    head = deleteAtEnd(head);
    printf("After deletion at the end: \n");
    forwardTraversal(head);
    printf("\n");
    
    int posIns = 2;
    head = insertAtPosition(head, posIns, 75);
    printf("After insertion at position %d: \n", posIns);
    forwardTraversal(head);
    printf("\n");

    int posDel = 2;
    head = deleteAtPosition(head, posDel);
    printf("After deletion at position %d: \n", posDel);
    forwardTraversal(head);
    printf("\n");

    return 0;
}

