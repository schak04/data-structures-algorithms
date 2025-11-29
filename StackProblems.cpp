/*
 * Stack Problems - Next Greater Element (NGE)
 * 
 * Finds the next greater element for each element in an array.
 * For each element, finds the first element to its right that is greater.
 */

#include <iostream>
#include <vector>
#include <stack>

class StackProblems {
private:
    std::vector<int> arr;
    int top;
    static constexpr int MAX = 100;

public:
    /**
     * Constructor
     */
    StackProblems() : top(-1) {
        arr.resize(MAX);
    }

    /**
     * Check if stack is empty
     */
    bool isEmpty() const {
        return top == -1;
    }

    /**
     * Check if stack is full
     */
    bool isFull() const {
        return top == MAX - 1;
    }

    /**
     * Push element onto stack
     * @param value Value to push
     */
    void push(int value) {
        if (isFull()) {
            std::cout << "Cannot push. Stack is already full." << std::endl;
            return;
        }
        std::cout << "Element successfully pushed: " << value << std::endl;
        arr[++top] = value;
    }

    /**
     * Pop element from stack
     * @return Popped value, or -1 if empty
     */
    int pop() {
        if (isEmpty()) {
            std::cout << "Cannot pop. Stack is already empty." << std::endl;
            return -1;
        }
        std::cout << "Element successfully popped: " << arr[top] << std::endl;
        return arr[top--];
    }

    /**
     * Peek at top element
     */
    void peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return;
        }
        std::cout << "Element at the top: " << arr[top] << std::endl;
    }

    /**
     * Next Greater Element - finds next greater element for each element
     * @param size Number of elements in stack
     */
    void nextGreaterElement(int size) const {
        std::cout << "Next Greater Element for each element:" << std::endl;
        
        for (int i = 0; i < size; i++) {
            int current = arr[i];
            int found = -1;
            
            // Look for next greater element
            for (int j = i + 1; j < size; j++) {
                if (arr[j] > current) {
                    found = arr[j];
                    break;
                }
            }
            
            std::cout << current << " -> " << found << std::endl;
        }
    }

    /**
     * Display stack elements (from top to bottom)
     * @param n Number of elements
     */
    void display(int n) const {
        std::cout << "Stack elements (top to bottom): ";
        for (int i = n - 1; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    /**
     * Optimized NGE using stack (O(n) time complexity)
     * @param elements Input array
     */
    static void nextGreaterElementOptimized(const std::vector<int>& elements) {
        std::cout << "\nOptimized NGE (using stack):" << std::endl;
        
        std::vector<int> result(elements.size(), -1);
        std::stack<int> stk;

        for (int i = 0; i < elements.size(); i++) {
            while (!stk.empty() && elements[stk.top()] < elements[i]) {
                result[stk.top()] = elements[i];
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i] << " -> " << result[i] << std::endl;
        }
    }
};

int main() {
    StackProblems stack;
    int n, x;

    std::cout << "Enter the number of elements you want in your stack: ";
    std::cin >> n;

    std::cout << "Enter the elements of the stack:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        stack.push(x);
    }

    stack.nextGreaterElement(n);
    stack.display(n);
    stack.peek();

    // Demo with optimized version
    std::vector<int> testArray = {4, 5, 2, 25, 7, 8};
    StackProblems::nextGreaterElementOptimized(testArray);

    return 0;
}

