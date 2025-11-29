/*
 * Deletion at Given Position in Doubly Linked List
 * 
 * Deletes a node at a specific position in a doubly linked list.
 */

#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        
        Node(int d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;

public:
    /**
     * Constructor
     */
    DoublyLinkedList() : head(nullptr) {}

    /**
     * Destructor
     */
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * Push a node at the beginning
     * @param new_data Value to insert
     */
    void push(int new_data) {
        Node* newNode = new Node(new_data);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    /**
     * Delete a node at given position (1-based)
     * @param n Position to delete from
     */
    void deleteNodeAtGivenPos(int n) {
        if (head == nullptr || n <= 0) {
            return;
        }

        Node* temp = head;
        int count = 1;

        // Traverse to the node at the given position
        while (temp != nullptr && count < n) {
            temp = temp->next;
            count++;
        }

        // If the position is more than the number of nodes
        if (temp == nullptr) {
            return;
        }

        // Delete the node
        if (head == temp) {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    /**
     * Print the list
     */
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int n, data;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        dll.push(data);
    }

    std::cout << "Before deletion: ";
    dll.printList();

    int pos;
    std::cout << "Enter position to delete: ";
    std::cin >> pos;

    dll.deleteNodeAtGivenPos(pos);

    std::cout << "After deletion: ";
    dll.printList();

    // Demo
    std::cout << "\n=== Demo ===" << std::endl;
    DoublyLinkedList demo;
    demo.push(4);
    demo.push(3);
    demo.push(2);
    demo.push(1);
    
    std::cout << "Original: ";
    demo.printList();
    
    demo.deleteNodeAtGivenPos(2);
    std::cout << "After deleting position 2: ";
    demo.printList();

    return 0;
}

