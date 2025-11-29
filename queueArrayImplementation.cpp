/*
 * Queue Implementation using Array
 * 
 * A queue is a FIFO (First In First Out) data structure.
 * This implementation uses a linear array.
 */

#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> arr;
    int front;
    int rear;
    int capacity;

public:
    /**
     * Constructor
     * @param cap Maximum capacity of the queue
     */
    Queue(int cap = 100) : capacity(cap), front(-1), rear(-1) {
        arr.resize(capacity);
    }

    /**
     * Check if queue is full
     */
    bool isFull() const {
        return rear == capacity - 1;
    }

    /**
     * Check if queue is empty
     */
    bool isEmpty() const {
        return front == -1 || front > rear;
    }

    /**
     * Add element to the rear of the queue
     * @param value Value to enqueue
     */
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow. Cannot insert any more elements.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
        std::cout << "The value inserted is " << value << ".\n";
    }

    /**
     * Remove element from the front of the queue
     * @return Dequeued value, or -1 if empty
     */
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow. Cannot remove any more elements.\n";
            return -1;
        }

        int value = arr[front];
        std::cout << "Dequeued Element: " << value << "\n";

        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }

        return value;
    }

    /**
     * Display all elements in the queue
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to display.\n";
            return;
        }

        std::cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    /**
     * Get the front element without removing it
     */
    void getFront() const {
        if (isEmpty()) {
            std::cout << "The queue is empty. There's nothing at the front.\n";
            return;
        }
        std::cout << "Element at the front of the queue is: " << arr[front] << "\n";
    }
};

int main() {
    Queue q;

    std::cout << "Initialising a queue...\n";
    std::cout << "Queue initialised!\n";
    
    std::cout << "Enqueuing elements into the queue...\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    std::cout << "Displaying the queue...\n";
    q.display();
    q.getFront();
    
    std::cout << "Dequeuing one element..\n";
    q.dequeue();
    q.getFront();
    
    std::cout << "Displaying the queue...\n";
    q.display();
    
    std::cout << "Dequeuing the rest of the elements...\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    std::cout << "Displaying the queue...\n";
    q.display();

    return 0;
}

