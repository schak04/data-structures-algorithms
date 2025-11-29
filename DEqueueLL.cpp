/*
 * Deque (Double-Ended Queue) Implementation using Linked List
 * 
 * A deque allows insertion and deletion from both ends.
 * This implementation uses a singly linked list.
 */

#include <iostream>

class Deque {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    /**
     * Constructor
     */
    Deque() : front(nullptr), rear(nullptr) {}

    /**
     * Destructor
     */
    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

    /**
     * Check if deque is empty
     */
    bool isEmpty() const {
        return front == nullptr;
    }

    /**
     * Insert element at the front
     * @param data Value to insert
     */
    void insertFront(int data) {
        Node* newNode = new Node(data);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front = newNode;
        }
        
        std::cout << data << " inserted at the front" << std::endl;
    }

    /**
     * Insert element at the rear
     * @param data Value to insert
     */
    void insertRear(int data) {
        Node* newNode = new Node(data);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        std::cout << data << " inserted at the rear" << std::endl;
    }

    /**
     * Delete element from the front
     */
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty, cannot delete from front." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // Deque becomes empty
        }

        std::cout << "Deleted " << temp->data << " from the front" << std::endl;
        delete temp;
    }

    /**
     * Delete element from the rear
     */
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty, cannot delete from rear." << std::endl;
            return;
        }

        // If only one element
        if (front == rear) {
            std::cout << "Deleted " << rear->data << " from the rear" << std::endl;
            delete rear;
            front = rear = nullptr;
            return;
        }

        // Traverse to the second last node
        Node* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }

        std::cout << "Deleted " << rear->data << " from the rear" << std::endl;
        delete rear;
        rear = temp;
        rear->next = nullptr;
    }

    /**
     * Display all elements in the deque
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        std::cout << "Deque: ";
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertFront(40);

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    return 0;
}

