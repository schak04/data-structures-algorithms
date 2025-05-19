// Evaluate from left to right 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strlen() function
#include <ctype.h>   // For isdigit() function
#define MAX 100      // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    int arr[MAX];
};
// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}
// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}
// Push an element to the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        //exit(1);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        //exit(1);
        return -1;
    }
    return s->arr[(s->top)--];
}

// Evaluate the postfix expression
int evaluatePostfix(char* expression) {
    struct Stack s;
    initStack(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');  // Convert character to integer
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (expression[i]) {
                case '+':
                    push(&s, val2 + val1);
                    break;
                case '-':
                    push(&s, val2 - val1);
                    break;
                case '*':
                    push(&s, val2 * val1);
                    break;
                case '/':
                    push(&s, val2 / val1);
                    break;
            }
        }
    }
    
    // The final result will be the only element in the stack
    return pop(&s);
}

int main() {
    char expression[] = "23*3+";
    
    int result = evaluatePostfix(expression);
    
    printf("The result is: %d\n", result);
    
    return 0;
}

