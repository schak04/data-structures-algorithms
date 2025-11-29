/*
 * Postfix Expression Evaluation
 * 
 * Evaluates postfix expressions using a stack.
 * Operands are pushed onto the stack, and operators pop two operands,
 * perform the operation, and push the result back.
 */

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>
#include <vector>

class PostfixEvaluator {
public:
    /**
     * Evaluate a postfix expression
     * @param expression Postfix expression string
     * @return Result of the evaluation
     */
    static int evaluate(const std::string& expression) {
        std::stack<int> stk;
        
        for (char ch : expression) {
            if (std::isdigit(ch)) {
                // Operand: push to stack
                stk.push(ch - '0');
            } else if (isOperator(ch)) {
                // Operator: pop two operands and perform operation
                if (stk.size() < 2) {
                    throw std::runtime_error("Invalid postfix expression: insufficient operands");
                }
                
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                
                int result = performOperation(ch, val2, val1);
                stk.push(result);
            }
        }
        
        if (stk.size() != 1) {
            throw std::runtime_error("Invalid postfix expression: too many operands");
        }
        
        return stk.top();
    }

private:
    /**
     * Check if character is an operator
     */
    static bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
    /**
     * Perform arithmetic operation
     */
    static int performOperation(char op, int a, int b) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) {
                    throw std::runtime_error("Division by zero");
                }
                return a / b;
            case '^': {
                int result = 1;
                for (int i = 0; i < b; i++) {
                    result *= a;
                }
                return result;
            }
            default:
                throw std::runtime_error("Unknown operator");
        }
    }
};

int main() {
    // Test case from original C code
    std::string expression = "23*3+";
    
    try {
        int result = PostfixEvaluator::evaluate(expression);
        std::cout << "Postfix expression: " << expression << std::endl;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Additional test cases
    std::cout << "\n=== Additional Test Cases ===\n";
    
    std::vector<std::string> testCases = {
        "12+3*",      // (1+2)*3 = 9
        "123*+",      // 1+2*3 = 7
        "52+3*",      // (5+2)*3 = 21
        "93/2+",      // 9/3+2 = 5
        "23^4+",      // 2^3+4 = 12
    };
    
    for (const auto& expr : testCases) {
        try {
            int result = PostfixEvaluator::evaluate(expr);
            std::cout << expr << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << expr << " -> Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}

