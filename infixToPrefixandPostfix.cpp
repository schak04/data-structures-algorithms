/*
 * Infix to Prefix and Postfix Conversion
 * 
 * Converts infix expressions to both prefix and postfix notation
 * using stack-based algorithms.
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

class ExpressionConverter {
private:
    /**
     * Check if a character is an operator
     */
    static bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    /**
     * Get operator precedence
     * Higher number = higher precedence
     */
    static int precedence(char op) {
        switch (op) {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            case '^': return 3;
            default: return 0;
        }
    }

public:
    /**
     * Convert infix expression to postfix
     * @param infix Input infix expression
     * @return Postfix expression
     */
    static std::string infixToPostfix(const std::string& infix) {
        std::stack<char> stk;
        std::string postfix;
        
        for (char ch : infix) {
            if (std::isalnum(ch)) {
                // Operand: add directly to output
                postfix += ch;
            } else if (ch == '(') {
                // Left parenthesis: push to stack
                stk.push(ch);
            } else if (ch == ')') {
                // Right parenthesis: pop until '('
                while (!stk.empty() && stk.top() != '(') {
                    postfix += stk.top();
                    stk.pop();
                }
                if (!stk.empty()) {
                    stk.pop(); // Remove '('
                }
            } else if (isOperator(ch)) {
                // Operator: pop higher or equal precedence operators
                while (!stk.empty() && stk.top() != '(' && 
                       precedence(stk.top()) >= precedence(ch)) {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        
        // Pop remaining operators
        while (!stk.empty()) {
            postfix += stk.top();
            stk.pop();
        }
        
        return postfix;
    }

    /**
     * Convert infix expression to prefix
     * @param infix Input infix expression
     * @return Prefix expression
     */
    static std::string infixToPrefix(const std::string& infix) {
        // Step 1: Reverse the infix expression
        std::string reversed = infix;
        std::reverse(reversed.begin(), reversed.end());
        
        // Step 2: Replace '(' with ')' and vice versa
        for (char& c : reversed) {
            if (c == '(') {
                c = ')';
            } else if (c == ')') {
                c = '(';
            }
        }
        
        // Step 3: Convert to postfix
        std::string postfix = infixToPostfix(reversed);
        
        // Step 4: Reverse the result to get prefix
        std::reverse(postfix.begin(), postfix.end());
        
        return postfix;
    }
};

int main() {
    std::string infix;
    
    std::cout << "Enter an infix expression: ";
    std::cin >> infix;
    
    // Convert to prefix and postfix
    std::string prefix = ExpressionConverter::infixToPrefix(infix);
    std::string postfix = ExpressionConverter::infixToPostfix(infix);
    
    std::cout << "Infix expression: " << infix << std::endl;
    std::cout << "Prefix expression: " << prefix << std::endl;
    std::cout << "Postfix expression: " << postfix << std::endl;
    
    // Demo with sample expressions
    std::cout << "\n=== Sample Expressions ===\n";
    
    std::vector<std::string> testCases = {
        "A+B*C",
        "(A+B)*C",
        "A+B-C*D",
        "A^B*C-D+E/F/(G+H)"
    };
    
    for (const auto& expr : testCases) {
        std::cout << "\nInfix: " << expr << std::endl;
        std::cout << "Prefix: " << ExpressionConverter::infixToPrefix(expr) << std::endl;
        std::cout << "Postfix: " << ExpressionConverter::infixToPostfix(expr) << std::endl;
    }
    
    return 0;
}

