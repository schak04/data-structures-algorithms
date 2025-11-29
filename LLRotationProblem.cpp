/*
 * Linked List Rotation Problem
 * 
 * Rotates a singly linked list by k positions.
 * Example: 10->20->30->40->50 with k=3 becomes 40->50->10->20->30
 * 
 * This implementation rotates by moving the first node to the end k times.
 */

#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        
        Node(int d) : data(d), next(nullptr) {}
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
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * Create and add a node
     * @param new_data Value to add
     */
    void addNode(int new_data) {
        Node* newNode = new Node(new_data);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    /**
     * Rotate the linked list left by k nodes
     * @param k Number of positions to rotate
     */
    void rotate(int k) {
        if (k == 0 || head == nullptr) {
            return;
        }

        // Rotate the list by k nodes
        for (int i = 0; i < k; i++) {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }

            // Move the first node to the last
            curr->next = head;
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
        }
    }

    /**
     * Optimized rotation (O(n) instead of O(k*n))
     * @param k Number of positions to rotate
     */
    void rotateOptimized(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        // Find length and last node
        int length = 1;
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
            length++;
        }

        // Calculate effective rotation
        k = k % length;
        if (k == 0) {
            return;
        }

        // Find the new tail (node at position length - k)
        Node* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        // Update pointers
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        last->next = head;
        head = newHead;
    }

    /**
     * Print the list
     */
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList sll;

    // Create list: 10 -> 20 -> 30 -> 40
    sll.addNode(10);
    sll.addNode(20);
    sll.addNode(30);
    sll.addNode(40);

    std::cout << "Original list: ";
    sll.printList();

    sll.rotate(6);
    std::cout << "After rotating by 6: ";
    sll.printList();

    // Demo with optimized version
    std::cout << "\n=== Optimized Rotation Demo ===" << std::endl;
    SinglyLinkedList sll2;
    sll2.addNode(10);
    sll2.addNode(20);
    sll2.addNode(30);
    sll2.addNode(40);
    sll2.addNode(50);

    std::cout << "Original: ";
    sll2.printList();

    sll2.rotateOptimized(3);
    std::cout << "After rotating by 3 (optimized): ";
    sll2.printList();

    return 0;
}

