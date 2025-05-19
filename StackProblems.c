#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX-1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Cannot push. Stack is already full.");
        return;
    }
    printf("Element successfully pushed: %d\n", value);
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Cannot pop. Stack is already empty.\n");
        return -1;
    }
    printf("Element successfully popped: %d\n", stack->arr[stack->top--]);
    return 0;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    printf("Element at the top: %d\n", stack->arr[stack->top]);
}

// next greater function
void NGE(struct Stack* stack, int size) {
    printf("Next Greater Function is goin to print stuff now:\n");
    for (int i=0; i<size; i++) {
        int current = stack->arr[i];
        int found = -1;
        for (int j=i+1; j<size; j++) {
            if (stack->arr[j] > current) {
                found = stack->arr[j];
                break;
            }
        }
        printf("%d %d\n", current, found);
    }
}

void stacker(struct Stack* stack, int n) {
    printf("Stack elements: ");
    for (int i=n-1; i>=0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int n, x;
    printf("Enter the number of elements you want in your stack: ");
    scanf("%d", &n);
    printf("Enter the elements of the stack:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        push(&stack, x);
    }
    NGE(&stack, n);
    stacker(&stack, n);
    peek(&stack);

    return 0;
}