/* 
Displaying the list:
We use while (temp != null) because we want to visit every node,
including the last one.

Inserting at the end:
We use while (temp->next != null) because we need to stop at the last node. 
This allows us to add a new node by attaching it to the last node’s next.

Why the difference?
When displaying, we need to process all the nodes, so we check temp != null.
When inserting at the end, we need to stop right before NULL (at the last node),
so we check temp->next != null.
*/

/* Singly Linked List */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    
};

struct node* createNode(int value)
{
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1-> data=value;
    node1-> next=NULL;
    return node1; // always return the new node after creating it
}

void printList(struct node* head)
{
    struct node* current = head;
    while(current!=NULL)
    {
        printf("%d -> " , current->data);
        current=current->next; // never forget to move to the next node or the loop will become an infinite loop
    }
    printf("NULL");
}

struct node* insertAtBeg(struct node* head, int value)
{
    struct node* node1=createNode(value);
    node1->next=head;
    head=node1;
    return head;
}

struct node* insertAtEnd(struct node* head, int value)
{
    struct node* node1=createNode(value);
    if(head==NULL)
    {
        return node1;
    }
    struct node* last = head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=node1;
    return head;
}

struct node* insertAtPos(struct node* head, int value, int position)
{
    struct node* node1 = createNode(value);
    struct node* current = head;
    for (int i = 1; (i < position - 1 && current != NULL); ++i)
    {
        current = current->next;
    }
    node1->next = current->next;
    current->next = node1;
    return head;
}

struct node* deleteAtBeg(struct node* head)
{    
    // Base case if linked list is empty
    if (head == NULL)
        return NULL;

    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node* deleteAtPos(struct node* head, int position)
{
    struct node* prev = NULL;
    struct node* curr = head;

    // Base case if linked list is empty
    if (curr == NULL) return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        deleteAtBeg(head);
    }

    // Case 2: Node to be deleted is in the middle
    // Traverse till the given position
    for (int i = 1; (i < position  && curr != NULL); i++) {
        prev = curr;
        curr = curr->next;
    }

    // If the given position is found, delete node
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
    // If the given position is not present
    else {
        printf("Data not present\n");
    }

    return head;
}

// Function to remove the last node of the linked list
struct node* deleteAtEnd(struct node* head)
{
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the list has only one node, delete it and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Find the second last node
    struct node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // Delete the last node
    free(second_last->next);

    // Change next of second last
    second_last->next = NULL;

    return head;
}

int main()
{
    struct node* head = createNode(10);
    printList(head);
    
    printf("\n");
    head=insertAtBeg(head,15);
    printList(head);
    
    printf("\n");
    head=insertAtBeg(head,6);
    printList(head);
    
    
    printf("\n");
    head=insertAtEnd(head,45);
    printList(head);
    
    printf("\n");
    head=insertAtEnd(head,12);
    
    printf("Linked list before insertion: ");
    printList(head);
    
    //Insert a new node with data 123 at position 3
    int data = 123, pos = 3;
    head = insertAtPos(head, data, pos);
    printf("\n");
    printf("Linked list after insertion of %d at position %d: ", data, pos);
    printList(head);
    head=deleteAtBeg(head);
    printf("\nAfter deletion from beginning: ");
    printList(head);
    
    
    
    return 0;
}
