/* 
Circular Queue using Array in C++

- This implementation uses a fixed-size array.
- The queue supports enqueue, dequeue, front, rear, and isFull/isEmpty checks.
*/

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Enqueue operation
    bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;
        return true;
    }

    // Dequeue operation
    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return false;
        }

        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

// Example usage
int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Queue full after this

    q.display();

    q.dequeue(); // remove 10
    q.dequeue(); // remove 20

    q.enqueue(60);
    q.enqueue(70); // Wraps around

    q.display();

    cout << "Front: " << q.getFront() << "\n";
    cout << "Rear: " << q.getRear() << "\n";

    return 0;
}
