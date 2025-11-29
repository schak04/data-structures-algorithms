/*
 * Doubly Linked List Implementation
 * 
 * A doubly linked list allows traversal in both directions.
 * Each node has pointers to both next and previous nodes.
 * 
 * Note:
 * 1. During insertion at a position, always update the prev and next 
 *    pointers of the new node first, then update surrounding nodes.
 * 2. During deletion at a position, update surrounding nodes first,
 *    then set the node's pointers to nullptr, and finally delete it.
 */

#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
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
            deleteAtBeginning();
        }
    }

    /**
     * Forward traversal
     */
    void forwardTraversal() const {
        Node* temp = head;
        std::cout << "NULL <-> ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    /**
     * Backward traversal (requires tail, but we'll traverse from end)
     */
    void backwardTraversal() const {
        if (head == nullptr) {
            std::cout << "NULL" << std::endl;
            return;
        }

        // Find tail
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        std::cout << "NULL <-> ";
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL" << std::endl;
    }

    /**
     * Insert at the beginning
     * @param value Value to insert
     */
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        
        head = newNode;
    }

    /**
     * Insert at the end
     * @param value Value to insert
     */
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        
        curr->next = newNode;
        newNode->prev = curr;
    }

    /**
     * Delete from the beginning
     */
    void deleteAtBeginning() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    /**
     * Delete from the end
     */
    void deleteAtEnd() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    /**
     * Insert at a specific position (1-based)
     * @param position Position to insert at
     * @param value Value to insert
     */
    void insertAtPosition(int position, int value) {
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            delete newNode;
            return;
        }

        if (current->next != nullptr) {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        } else {
            // Insert at end
            current->next = newNode;
            newNode->prev = current;
        }
    }

    /**
     * Delete at a specific position (1-based)
     * @param position Position to delete from
     */
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            if (position == 1) {
                delete head;
                head = nullptr;
            }
            return;
        }

        if (position == 1) {
            deleteAtBeginning();
            return;
        }

        Node* current = head;
        for (int i = 1; i < position && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            return;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        
        current->next = nullptr;
        current->prev = nullptr;
        delete current;
    }
};

int main() {
    DoublyLinkedList dll;

    // Create initial list
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(4);

    std::cout << "Forward Traversal of the doubly-linked list:" << std::endl;
    dll.forwardTraversal();

    std::cout << "Backward Traversal of the doubly-linked list:" << std::endl;
    dll.backwardTraversal();

    dll.insertAtBeginning(20);
    std::cout << "\nAfter insertion at the beginning:" << std::endl;
    dll.forwardTraversal();

    dll.insertAtEnd(66);
    std::cout << "After insertion at the end:" << std::endl;
    dll.forwardTraversal();

    dll.deleteAtBeginning();
    std::cout << "After deletion at the beginning:" << std::endl;
    dll.forwardTraversal();

    dll.deleteAtEnd();
    std::cout << "After deletion at the end:" << std::endl;
    dll.forwardTraversal();

    dll.insertAtPosition(2, 75);
    std::cout << "After insertion at position 2:" << std::endl;
    dll.forwardTraversal();

    dll.deleteAtPosition(2);
    std::cout << "After deletion at position 2:" << std::endl;
    dll.forwardTraversal();

    return 0;
}

