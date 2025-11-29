/*
 * Doubly Linked List Implementation (Variant 2)
 * 
 * Alternative implementation with different function names and structure.
 * Includes forward/backward traversal, insertion, and deletion operations.
 */

#include <iostream>

class DoublyLinkedList2 {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        
        Node(int d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;

    /**
     * Get tail node
     */
    Node* getTail() const {
        if (head == nullptr) return nullptr;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

public:
    /**
     * Constructor
     */
    DoublyLinkedList2() : head(nullptr) {}

    /**
     * Destructor
     */
    ~DoublyLinkedList2() {
        while (head != nullptr) {
            delHead();
        }
    }

    /**
     * Forward traversal
     */
    void forwardTraversal() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /**
     * Backward traversal
     */
    void backwardTraversal() const {
        Node* tail = getTail();
        Node* curr = tail;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->prev;
        }
        std::cout << std::endl;
    }

    /**
     * Insert at the beginning
     * @param data Value to insert
     */
    void insertBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        }
        
        head = newNode;
    }

    /**
     * Insert at the end
     * @param new_data Value to insert
     */
    void insertEnd(int new_data) {
        Node* newNode = new Node(new_data);

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
     * Insert at a specific position (1-based)
     * @param pos Position to insert at
     * @param new_data Value to insert
     */
    void insertAtPosition(int pos, int new_data) {
        Node* newNode = new Node(new_data);

        if (pos == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            std::cout << "Position is out of bounds." << std::endl;
            delete newNode;
            return;
        }

        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next = newNode;
        
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    /**
     * Print the list
     */
    void printList() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /**
     * Delete the head node
     */
    void delHead() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    /**
     * Delete the last node
     */
    void delLast() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->prev->next = nullptr;
        delete curr;
    }

    /**
     * Delete at a specific position (1-based)
     * @param pos Position to delete from
     */
    void delPos(int pos) {
        if (head == nullptr) {
            return;
        }

        Node* curr = head;
        for (int i = 1; curr != nullptr && i < pos; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            return;
        }

        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        if (head == curr) {
            head = curr->next;
        }

        delete curr;
    }
};

int main() {
    DoublyLinkedList2 dll;

    // Create initial list
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);

    std::cout << "Forward Traversal:" << std::endl;
    dll.forwardTraversal();

    std::cout << "Backward Traversal:" << std::endl;
    dll.backwardTraversal();

    std::cout << "Original Linked List: ";
    dll.printList();

    dll.insertBegin(40);
    std::cout << "After inserting Node at the front: ";
    dll.printList();

    dll.insertEnd(50);
    std::cout << "Inserting Node with data at the end: ";
    dll.printList();

    dll.insertAtPosition(3, 60);
    std::cout << "Inserting Node with data at position 3: ";
    dll.printList();

    dll.delHead();
    std::cout << "After Deletion at the beginning: ";
    dll.printList();

    dll.delLast();
    std::cout << "After Deletion at the end: ";
    dll.printList();

    dll.delPos(2);
    std::cout << "After Deletion at position 2: ";
    dll.printList();

    return 0;
}

