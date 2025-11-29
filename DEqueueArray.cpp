/*
 * Deque (Double-Ended Queue) Implementation using Array
 * 
 * A deque allows insertion and deletion from both ends.
 * This implementation uses a linear array (non-circular).
 */

#include <iostream>
#include <vector>
#include <stdexcept>

class Deque {
private:
    std::vector<int> arr;
    int front;
    int rear;
    int capacity;

public:
    /**
     * Constructor
     * @param cap Maximum capacity of the deque
     */
    Deque(int cap = 10) : capacity(cap), front(-1), rear(-1) {
        arr.resize(capacity);
    }

    /**
     * Check if deque is empty
     */
    bool isEmpty() const {
        return front == -1;
    }

    /**
     * Check if deque is full
     */
    bool isFull() const {
        return rear == capacity - 1;
    }

    /**
     * Insert element at the front
     * @param value Value to insert
     */
    void insertFront(int value) {
        if (isFull()) {
            std::cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            std::cout << "Cannot insert at front, no space\n";
            return;
        } else {
            front--;
        }

        arr[front] = value;
        std::cout << "Inserted " << value << " at front\n";
    }

    /**
     * Insert element at the rear
     * @param value Value to insert
     */
    void insertRear(int value) {
        if (isFull()) {
            std::cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        std::cout << "Inserted " << value << " at rear\n";
    }

    /**
     * Delete element from the front
     * @return Deleted value, or -1 if empty
     */
    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }

        int value = arr[front];
        std::cout << "Removed from front: " << value << "\n";

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front++;
        }

        return value;
    }

    /**
     * Delete element from the rear
     * @return Deleted value, or -1 if empty
     */
    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }

        int value = arr[rear];
        std::cout << "Removed from rear: " << value << "\n";

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            rear--;
        }

        return value;
    }

    /**
     * Get front element without removing it
     * @return Front element, or -1 if empty
     */
    int getFront() const {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    /**
     * Get rear element without removing it
     * @return Rear element, or -1 if empty
     */
    int getRear() const {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return arr[rear];
    }

    /**
     * Display all elements in the deque
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return;
        }

        std::cout << "Deque elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Deque dq(10);

    // Insert operations
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(30);
    dq.insertFront(40);

    dq.display();

    // Delete operations
    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    std::cout << "Front element: " << dq.getFront() << "\n";
    std::cout << "Rear element: " << dq.getRear() << "\n";

    return 0;
}

