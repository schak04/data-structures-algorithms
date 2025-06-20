#include <stdio.h>
#include <stdlib.h>

// In header linked lists, the data of header stores the no. of nodes present

/* Grounded Header Linked List */


// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};


struct node* createNode(int value)
{
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data=value;
    node1->next=NULL;
    return node1;
}

// Function to display the list
void displayList(struct node* header) {
    struct node* current = header->next;  // Skip the header node
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    printf("NULL\n");
    printf("The number of nodes are : %d" , header->data);
    
}

// Function to insert a node at the beginning of the list (after the header)
struct node* insertAtBeginning(struct node* header, int newData) {
    // Create a new node
    struct node* newNode=createNode(newData);


    // Point the new node to the current first node
    newNode->next = header->next;

    // Update the header to point to the new node
    header->next=newNode;
    header->data+=1;

    //printf("Node inserted at the beginning with data: %d\n", newData);
    return header; 
}

// Function to insert a node at the end of the grounded header linked list
struct node* insertAtEnd(struct node* header, int data) {
    struct node* temp = header;
    
    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Create a new node
    struct node* newNode = createNode(data);
    
    // Insert the new node at the end
    temp->next = newNode;
    header->data+=1;
    return header;
}


// Function to insert a node at a specific position
struct node* insertAtPosition(struct node* header, int position, int data) {
    
    // Create a new node
    struct node* newNode = createNode(data);

    struct node* temp = header;

    // Traverse the list to find the node before the insertion point
    for (int i = 1; i < position; i++) {
        if (temp->next == NULL) {
            printf("Position %d is out of bounds. Node will be inserted at the end.\n", position);
            break;
        }
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d with data: %d\n", position, data);
    header->data+=1;
    return header;
}

// Function to delete the first node after the header
struct node* deleteAtBeginning(struct node* header) {
    if (header->next == NULL) {
        printf("The list is empty. No node to delete.\n");
        return header;
    }

    // The node to be deleted is the first actual node after the header
    struct node* temp = header->next;

    // Update the header to point to the second node
    header->next = temp->next;

    // Free the memory of the deleted node
    free(temp);
    header->data-=1;
    
    printf("Node deleted from the beginning.\n");
    return header;
}

// Function to delete the last node of the list
struct node* deleteAtEnd(struct node* header) {
    if (header->next == NULL) {
        printf("The list is empty. No node to delete.\n");
        return header;
    }

    // Initialize two pointers
    struct node* prev = NULL;
    struct node* temp = header;

    // Traverse the list until the last node is reached
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // This condition checks if there is only one node in the list (after the header)
    if (prev == header) {
        header->next = NULL; // If the list has only one node, this line disconnects that node by setting header->next to NULL, making the list empty
    } else {
        prev->next = NULL;  // Disconnects the last node from the list
    }

    // Free the memory of the deleted node
    free(temp);
    header->data-=1;

    printf("Node deleted from the end.\n");
    return header;
}


// Function to delete a node at a specific position
struct node* deleteAtPosition(struct node* header, int position) {
    if (header->next == NULL) {
        printf("The list is empty. No node to delete.\n");
        return header;
    }

    // Initialize two pointers
    struct node* temp = header;
    struct node* prev = NULL;

    // Traverse the list to find the node at the specified position
    for (int i = 0; i < position; i++) {
        prev = temp;
        temp = temp->next;

        // If the position is out of bounds
        if (temp == NULL) {
            printf("Position %d is out of bounds. No node to delete.\n", position);
            return header;
        }
    }

    // Update the previous node's next pointer to skip the node at the position
    prev->next = temp->next;

    // Free the memory of the deleted node
    free(temp);
    header->data-=1;

    printf("Node deleted at position %d.\n", position);
    return header;
}



// Main function
int main() {
    // Create the header node (we can also simply use the createNode() function for this putting 0 as the argument)
    struct node* header = (struct node*)malloc(sizeof(struct node));
    header-> data=0;
    header->next = NULL;  // Initialize header's next to NULL
    

    // Insert some nodes into the list
    header = insertAtBeginning(header, 10);
    header = insertAtBeginning(header, 20);
    header = insertAtBeginning(header, 30);
    header = insertAtBeginning(header, 40);
    header = insertAtBeginning(header, 50);
    header = insertAtBeginning(header, 60);

    // Display the list
    displayList(header);
    
    // insert at end
    printf("\nInsertion at end\n");
    header = insertAtEnd(header,70);
    displayList(header);
    
    //insert at position
    printf("\n");
    header = insertAtPosition(header,3,80);
    displayList(header);
    
    

    // Delete the first node
    printf("\n");
    header = deleteAtBeginning(header);
    displayList(header);

    // Delete the last node
    printf("\n");
    header = deleteAtEnd(header);
    displayList(header);

   // Delete at position  
    printf("\n");
    header = deleteAtPosition(header, 2);
    displayList(header);
    
    // Free the header node. WHY??
    //free(header);

    return 0;
}

