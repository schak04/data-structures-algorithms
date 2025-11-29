/*
 * Rotation of a Doubly Linked List
 * 
 * Rotates a doubly linked list by k positions (left rotation).
 * Uses a temporary circular connection approach.
 */

#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        char data;
        Node* next;
        Node* prev;
        
        Node(char d) : data(d), next(nullptr), prev(nullptr) {}
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
     * Insert at the tail
     * @param data Character to insert
     */
    void insertAtTail(char data) {
        Node* newNode = new Node(data);

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
     * Display the list
     */
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    /**
     * Rotate the list by k positions (left rotation)
     * @param k Number of positions to rotate
     */
    void rotateByN(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        // Find the length of the list
        Node* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        // Make the list circular temporarily
        temp->next = head;
        head->prev = temp;

        // Calculate the effective number of rotations
        k = k % length;
        if (k == 0) {
            temp->next = nullptr;
            head->prev = nullptr;
            return;
        }

        // Move the head to the k-th node (to rotate left by k)
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // Set the new head
        Node* newHead = newTail->next;
        newHead->prev = nullptr;
        newTail->next = nullptr;

        head = newHead;
    }
};

int main() {
    DoublyLinkedList dll;
    int n, k;
    char data;

    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    std::cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        dll.insertAtTail(data);
    }

    std::cout << "Enter number of positions to rotate: ";
    std::cin >> k;

    std::cout << "Original list: ";
    dll.display();

    dll.rotateByN(k);

    std::cout << "Rotated list: ";
    dll.display();

    // Demo
    std::cout << "\n=== Demo ===" << std::endl;
    DoublyLinkedList demo;
    demo.insertAtTail('a');
    demo.insertAtTail('b');
    demo.insertAtTail('c');
    demo.insertAtTail('d');
    demo.insertAtTail('e');
    
    std::cout << "Original: ";
    demo.display();
    
    demo.rotateByN(2);
    std::cout << "After rotating by 2: ";
    demo.display();

    return 0;
}

