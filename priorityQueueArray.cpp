/*
 * Priority Queue Implementation using Array
 * 
 * A priority queue where elements with higher priority are dequeued first.
 * This implementation uses a simple array-based approach.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

class PriorityQueue {
private:
    struct Element {
        int value;
        int priority;
    };

    std::vector<Element> arr;
    int size;

public:
    /**
     * Constructor
     */
    PriorityQueue() : size(-1) {
        arr.resize(100); // MAX capacity
    }

    /**
     * Check if priority queue is empty
     */
    bool isEmpty() const {
        return size == -1;
    }

    /**
     * Check if priority queue is full
     */
    bool isFull() const {
        return size == 99; // MAX - 1
    }

    /**
     * Add element with priority to the queue
     * @param value Element value
     * @param priorityValue Priority (higher = dequeued first)
     */
    void enqueue(int value, int priorityValue) {
        if (isFull()) {
            std::cout << "Cannot enqueue. Queue is already full.\n";
            return;
        }

        size++;
        arr[size].value = value;
        arr[size].priority = priorityValue;
    }

    /**
     * Find index of element with highest priority
     * @return Index of highest priority element, or -1 if empty
     */
    int getHighestPriorityIndex() const {
        if (isEmpty()) {
            return -1;
        }

        int maxPriority = INT_MIN;
        int index = -1;

        for (int i = 0; i <= size; i++) {
            if (arr[i].priority > maxPriority) {
                maxPriority = arr[i].priority;
                index = i;
            }
        }

        return index;
    }

    /**
     * Remove and return element with highest priority
     * @return Value of dequeued element, or -1 if empty
     */
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return -1;
        }

        int index = getHighestPriorityIndex();
        int value = arr[index].value;

        // Shift elements to fill the gap
        for (int i = index; i < size; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        return value;
    }

    /**
     * Display all elements in the priority queue
     */
    void display() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }

        std::cout << "Priority Queue (value, priority): ";
        for (int i = 0; i <= size; i++) {
            std::cout << "(" << arr[i].value << "," << arr[i].priority << ") ";
        }
        std::cout << "\n";
    }
};

int main() {
    PriorityQueue pq;

    // Enqueue elements with priorities
    pq.enqueue(10, 3);
    pq.enqueue(20, 4);
    pq.enqueue(30, 2);
    pq.enqueue(40, 5);

    pq.display();

    std::cout << "Dequeued element: " << pq.dequeue() << "\n";

    pq.display();

    // Additional test
    std::cout << "\nAdding more elements...\n";
    pq.enqueue(50, 1);
    pq.enqueue(60, 6);
    pq.display();

    std::cout << "Dequeued element: " << pq.dequeue() << "\n";
    pq.display();

    return 0;
}

