/*
 * Singly Linked List Implementation
 * 
 * A singly linked list is a linear data structure where each node
 * points to the next node in the sequence.
 * 
 * Note:
 * - Displaying: use while (temp != null) to visit every node
 * - Inserting at end: use while (temp->next != null) to stop at last node
 */

#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    /**
     * Constructor
     */
    SinglyLinkedList() : head(nullptr) {}

    /**
     * Destructor
     */
    ~SinglyLinkedList() {
        while (head != nullptr) {
            deleteAtBeg();
        }
    }

    /**
     * Print the list
     */
    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << " -> NULL" << std::endl;
    }

    /**
     * Insert at the beginning
     * @param value Value to insert
     */
    void insertAtBeg(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
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

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    /**
     * Insert at a specific position (1-based)
     * @param value Value to insert
     * @param position Position to insert at
     */
    void insertAtPos(int value, int position) {
        Node* newNode = new Node(value);
        
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Position out of bounds" << std::endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    /**
     * Delete from the beginning
     */
    void deleteAtBeg() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    /**
     * Delete from a specific position (1-based)
     * @param position Position to delete from
     */
    void deleteAtPos(int position) {
        if (head == nullptr) {
            return;
        }

        if (position == 1) {
            deleteAtBeg();
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        for (int i = 1; i < position && curr != nullptr; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            std::cout << "Data not present" << std::endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
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

        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }

        delete secondLast->next;
        secondLast->next = nullptr;
    }
};

int main() {
    SinglyLinkedList sll;

    sll.insertAtEnd(10);
    sll.printList();

    sll.insertAtBeg(15);
    sll.printList();

    sll.insertAtBeg(6);
    sll.printList();

    sll.insertAtEnd(45);
    sll.printList();

    sll.insertAtEnd(12);
    std::cout << "Linked list before insertion: ";
    sll.printList();

    sll.insertAtPos(123, 3);
    std::cout << "Linked list after insertion of 123 at position 3: ";
    sll.printList();

    sll.deleteAtBeg();
    std::cout << "After deletion from beginning: ";
    sll.printList();

    return 0;
}

