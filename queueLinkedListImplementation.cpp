/*
 * Queue Implementation using Linked List
 * 
 * A queue is a FIFO (First In First Out) data structure.
 * This implementation uses a singly linked list.
 */

#include <iostream>

class Queue {
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
    Queue() : front(nullptr), rear(nullptr) {}

    /**
     * Destructor
     */
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    /**
     * Check if queue is empty
     */
    bool isEmpty() const {
        return front == nullptr;
    }

    /**
     * Add element to the rear of the queue
     * @param value Value to enqueue
     */
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        std::cout << "Enqueued element: " << value << std::endl;
    }

    /**
     * Remove element from the front of the queue
     */
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Cannot dequeue. The queue is empty already." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // Queue becomes empty
        }

        std::cout << "Dequeued element: " << temp->data << std::endl;
        delete temp;
    }

    /**
     * Display all elements in the queue
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << " -> NULL" << std::endl;
    }

    /**
     * Get the front element without removing it
     */
    int getFront() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;

    std::cout << "Initialising a queue..." << std::endl;
    std::cout << "Queue initialised!" << std::endl;
    
    std::cout << "Enqueuing elements into the queue..." << std::endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    std::cout << "Displaying the queue..." << std::endl;
    q.display();
    
    std::cout << "Dequeuing two elements.." << std::endl;
    q.dequeue();
    q.dequeue();
    
    std::cout << "Displaying the queue..." << std::endl;
    q.display();

    return 0;
}

