/*
 * Reverse Doubly Linked List using Recursion
 * 
 * Reverses a doubly linked list recursively by swapping
 * next and prev pointers of each node.
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

    /**
     * Recursive function to reverse the list
     * @param curr Current node being processed
     * @return New head of the reversed list
     */
    Node* reverseRecursive(Node* curr) {
        // Base case: If the list is empty or we reach the end
        if (curr == nullptr) {
            return nullptr;
        }

        // Swap the next and prev pointers
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // If the previous node (after swap) is NULL, this is the new head
        if (curr->prev == nullptr) {
            return curr;
        }

        // Recurse for the next node
        return reverseRecursive(curr->prev);
    }

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
        newNode->prev = temp;
    }

    /**
     * Reverse the list
     */
    void reverse() {
        head = reverseRecursive(head);
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

    // Create list: 1 <-> 2 <-> 3 <-> 4
    dll.addNode(1);
    dll.addNode(2);
    dll.addNode(3);
    dll.addNode(4);

    std::cout << "Original Linked list: ";
    dll.printList();

    dll.reverse();

    std::cout << "Reversed Linked list: ";
    dll.printList();

    // Demo with another list
    std::cout << "\n=== Additional Demo ===" << std::endl;
    DoublyLinkedList dll2;
    dll2.addNode(10);
    dll2.addNode(20);
    dll2.addNode(30);

    std::cout << "Original: ";
    dll2.printList();

    dll2.reverse();
    std::cout << "Reversed: ";
    dll2.printList();

    return 0;
}

