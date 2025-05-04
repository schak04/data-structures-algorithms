#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Function to traverse the doubly linked list 
// in forward direction
void forwardTraversal(struct Node* head) {
  
    // Start traversal from the head of the list
    struct Node* curr = head;

    // Continue until the current node is not
    // null (end of list)
    while (curr != NULL) {
        // Output data of the current node
        printf("%d ", curr->data);
      
        // Move to the next node
        curr = curr->next;
    }
    // Print newline after traversal
    printf("\n");
}

// Function to traverse the doubly linked list 
// in backward direction
void backwardTraversal(struct Node* tail) {
  
    // Start traversal from the tail of the list
    struct Node* curr = tail;

    // Continue until the current node is not 
    // null (end of list)
    while (curr != NULL) {
      
        // Output data of the current node
        printf("%d ", curr->data);
      
        // Move to the previous node
        curr = curr->prev;
    }

    // Print newline after traversal
    printf("\n");
}

// Insert a node at the beginning
struct Node* insertBegin(struct Node* head, int data) {
    
    // Create a new node
    struct Node* new_node = createNode(data);
    
    // Make next of it as head
    new_node->next = head;
    
    // Set previous of head as new node
    if (head != NULL) {
        head->prev = new_node;
    }
    
    // Return new node as new head
    return new_node;
}

// Function to insert a new node at the end of the 
//doubly linked list
struct Node* insertEnd(struct Node *head, int new_data) {
    struct Node *new_node = createNode(new_data);

    // If the linked list is empty, set the
     //new node as the head
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Set the next of last node to new node
        curr->next = new_node;
        // Set prev of new node to last node
        new_node->prev = curr;
    }
    return head;
}


// Function to insert a new node at a given position
struct Node * insertAtPosition(struct Node * head, int pos, int new_data) {
    // Create a new node
    struct Node * new_node = createNode(new_data);

    // Insertion at the beginning
    if (pos == 1) {
        new_node -> next = head;

        // If the linked list is not empty, set the 
      //prev of head to new node
        if (head != NULL) {
            head -> prev = new_node;
        }
        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }
    struct Node * curr = head;
    // Traverse the list to find the node before the insertion point
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr -> next;
    }
    // If the position is out of bounds
    if (curr == NULL) {
        printf("Position is out of bounds.\n");
        free(new_node);
        return head;
    }
    // Set the prev of new node to curr
    new_node -> prev = curr;
    // Set the next of new node to next of curr
    new_node -> next = curr -> next;
    // Update the next of current node to new node
    curr -> next = new_node;
    // If the new node is not the last node, update the prev of next node to new node
    if (new_node -> next != NULL) 
    {
        new_node -> next -> prev = new_node;
    }
    // Return the head of the doubly linked list
    return head;
}


// Print the doubly linked list
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
      printf("\n");
}

// Function to delete the first node (head) of the list
// and return the second node as the new head
struct Node *delHead(struct Node *head) {
    // If empty, return NULL
    if (head == NULL)
        return NULL;

    // Store in temp for deletion later
    struct Node *temp = head;

    // Move head to the next node
    head = head->next;

    // Set prev of the new head
    if (head != NULL)
        head->prev = NULL;

    // Free memory and return new head
    free(temp);
    return head;
}

struct Node* delLast(struct Node *head) {
  
    // Corner cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    // Traverse to the last node
    struct Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    // Update the previous node's next pointer
    curr->prev->next = NULL;

    // Delete the last node
    free(curr);
    // Return the updated head
    return head;
}

    


// Function to delete a node at a specific 
//position in the doubly linked list
struct Node * delPos(struct Node * head, int pos) {

    // If the list is empty
    if (head == NULL)
        return head;

    struct Node * curr = head;

    // Traverse to the node at the given position
    for (int i = 1; curr && i < pos; ++i) {
        curr = curr -> next;
    }

    // If the position is out of range
    if (curr == NULL)
        return head;

    // Update the previous node's next pointer
    if (curr -> prev)
        curr -> prev -> next = curr -> next;

    // Update the next node's prev pointer
    if (curr -> next)
        curr -> next -> prev = curr -> prev;

    // If the node to be deleted is the head node
    if (head == curr)
        head = curr -> next;

    // Deallocate memory for the deleted node
    free(curr);
    return head;
}


int main() {
  
    // Sample usage of the doubly linked list and 
    // traversal functions
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Forward Traversal:\n");
    forwardTraversal(head);

    printf("Backward Traversal:\n");
    backwardTraversal(third);

    // Print the original list
    printf("Original Linked List: ");
    printList(head);

    // Insert a new node at the front of the list
    head = insertBegin(head, 40);

    // Print the updated list
    printf("After inserting Node at the front: ");
    printList(head);

// Print the original list
    //printf("Original Linked List: ");
    //printList(head);

    // Insert a new node with data 40 at the end
    printf("Inserting Node  with data at the end: ");
    head = insertEnd(head, 50);

    // Print the updated list
    printList(head);


    // Print the original list
    //printf("Original Linked List: ");
    //printList(head);

    // Insert new node with data 60 at position 3
    printf("Inserting Node with data at position 3: ");
    int data = 60;
    int pos = 3;
    head = insertAtPosition(head, pos, data);

    // Print the updated list
    printList(head);


   //printf("Original Linked List: ");
    //printList(head);

    printf("After Deletion at the beginning: ");
    head = delHead(head);
    
    
    //printf("Original Linked List: ");
    printList(head);

    printf("After Deletion at the end: ");
    head = delLast(head);

    printList(head);


    //printf("Original Linked List: ");
    //printList(head);

    // Delete node at position 2
    head = delPos(head, 2);

    printf("After Deletion at position 2: ");
    printList(head);
    
    //printList(head);

    // Free memory allocated for nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
