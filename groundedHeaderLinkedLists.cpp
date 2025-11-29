/*
 * Grounded Header Linked List Implementation
 * 
 * In header linked lists, the header node's data stores the number of nodes present.
 * The header node is always present and points to the first actual data node.
 * "Grounded" means the list ends with NULL (not circular).
 */

#include <iostream>

class HeaderLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* header; // Header node (data stores count)

public:
    /**
     * Constructor - creates header node with count = 0
     */
    HeaderLinkedList() {
        header = new Node(0); // Header data stores count
    }

    /**
     * Destructor
     */
    ~HeaderLinkedList() {
        while (header->next != nullptr) {
            deleteAtBeginning();
        }
        delete header;
    }

    /**
     * Display the list
     */
    void displayList() const {
        Node* current = header->next; // Skip the header node
        
        if (current == nullptr) {
            std::cout << "The list is empty." << std::endl;
            std::cout << "The number of nodes are: " << header->data << std::endl;
            return;
        }

        std::cout << "List: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << " -> NULL" << std::endl;
        std::cout << "The number of nodes are: " << header->data << std::endl;
    }

    /**
     * Insert at the beginning (after header)
     * @param newData Value to insert
     */
    void insertAtBeginning(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = header->next;
        header->next = newNode;
        header->data++; // Increment count
    }

    /**
     * Insert at the end
     * @param data Value to insert
     */
    void insertAtEnd(int data) {
        Node* temp = header;

        // Traverse to the end of the list
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        Node* newNode = new Node(data);
        temp->next = newNode;
        header->data++; // Increment count
    }

    /**
     * Insert at a specific position (1-based, after header)
     * @param position Position to insert at
     * @param data Value to insert
     */
    void insertAtPosition(int position, int data) {
        Node* newNode = new Node(data);
        Node* temp = header;

        // Traverse to find the node before the insertion point
        for (int i = 1; i < position; i++) {
            if (temp->next == nullptr) {
                std::cout << "Position " << position 
                          << " is out of bounds. Node will be inserted at the end." << std::endl;
                break;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        header->data++; // Increment count
        std::cout << "Node inserted at position " << position 
                  << " with data: " << data << std::endl;
    }

    /**
     * Delete the first node after the header
     */
    void deleteAtBeginning() {
        if (header->next == nullptr) {
            std::cout << "The list is empty. No node to delete." << std::endl;
            return;
        }

        Node* temp = header->next;
        header->next = temp->next;
        delete temp;
        header->data--; // Decrement count
        std::cout << "Node deleted from the beginning." << std::endl;
    }

    /**
     * Delete the last node
     */
    void deleteAtEnd() {
        if (header->next == nullptr) {
            std::cout << "The list is empty. No node to delete." << std::endl;
            return;
        }

        Node* prev = nullptr;
        Node* temp = header;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == header) {
            // Only one node in the list
            header->next = nullptr;
        } else {
            prev->next = nullptr;
        }

        delete temp;
        header->data--; // Decrement count
        std::cout << "Node deleted from the end." << std::endl;
    }

    /**
     * Delete at a specific position (1-based, after header)
     * @param position Position to delete from
     */
    void deleteAtPosition(int position) {
        if (header->next == nullptr) {
            std::cout << "The list is empty. No node to delete." << std::endl;
            return;
        }

        Node* temp = header;
        Node* prev = nullptr;

        // Traverse to find the node at the specified position
        for (int i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;

            if (temp == nullptr) {
                std::cout << "Position " << position 
                          << " is out of bounds. No node to delete." << std::endl;
                return;
            }
        }

        prev->next = temp->next;
        delete temp;
        header->data--; // Decrement count
        std::cout << "Node deleted at position " << position << "." << std::endl;
    }
};

int main() {
    HeaderLinkedList list;

    // Insert nodes
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);
    list.insertAtBeginning(50);
    list.insertAtBeginning(60);

    list.displayList();

    std::cout << "\nInsertion at end" << std::endl;
    list.insertAtEnd(70);
    list.displayList();

    std::cout << "\nInsertion at position 3" << std::endl;
    list.insertAtPosition(3, 80);
    list.displayList();

    std::cout << "\nDeletion at beginning" << std::endl;
    list.deleteAtBeginning();
    list.displayList();

    std::cout << "\nDeletion at end" << std::endl;
    list.deleteAtEnd();
    list.displayList();

    std::cout << "\nDeletion at position 2" << std::endl;
    list.deleteAtPosition(2);
    list.displayList();

    return 0;
}

