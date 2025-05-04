#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack data structure definition
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Function to get the top element of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to define precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to reverse a string
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {  // If the character is an operand, add it to postfix
            postfix[j++] = ch;
        } else if (ch == '(') {  // If the character is '(', push it onto the stack
            push(&s, ch);
        } else if (ch == ')') {  // If the character is ')', pop until '(' is found
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop the '(' from the stack
        } else if (isOperator(ch)) {  // If the character is an operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Step 1: Reverse the infix expression
    reverseString(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert the modified infix expression to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverseString(postfix);

    // Step 5: Copy the reversed postfix expression (which is the prefix) to the output
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX], postfix[MAX];

    // Input infix expression from user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix and postfix
    infixToPrefix(infix, prefix);
    infixToPostfix(infix, postfix);

    // Output the resulting prefix and postfix expressions
    printf("Prefix expression: %s\n", prefix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
