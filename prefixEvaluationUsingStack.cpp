/*
 * Prefix Expression Evaluation
 * 
 * Evaluates prefix expressions using a stack.
 * Since prefix is evaluated right to left, we traverse from right to left.
 * Operands are pushed onto the stack, and operators pop two operands,
 * perform the operation, and push the result back.
 */

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>
#include <vector>

class PrefixEvaluator {
public:
    /**
     * Evaluate a prefix expression
     * @param expression Prefix expression string
     * @return Result of the evaluation
     */
    static int evaluate(const std::string& expression) {
        std::stack<int> stk;
        
        // Process from right to left
        for (int i = expression.length() - 1; i >= 0; i--) {
            char ch = expression[i];
            
            if (std::isdigit(ch)) {
                // Operand: push to stack
                stk.push(ch - '0');
            } else if (isOperator(ch)) {
                // Operator: pop two operands and perform operation
                if (stk.size() < 2) {
                    throw std::runtime_error("Invalid prefix expression: insufficient operands");
                }
                
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                
                int result = performOperation(ch, val1, val2);
                stk.push(result);
            }
        }
        
        if (stk.size() != 1) {
            throw std::runtime_error("Invalid prefix expression: too many operands");
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
     * Note: For prefix, val1 is the first operand, val2 is the second
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
    std::string expression = "-+7*45+20";
    
    try {
        int result = PrefixEvaluator::evaluate(expression);
        std::cout << "Prefix expression: " << expression << std::endl;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Additional test cases
    std::cout << "\n=== Additional Test Cases ===\n";
    
    std::vector<std::string> testCases = {
        "+12",        // 1+2 = 3
        "*+123",      // (1+2)*3 = 9
        "+*123",      // 1*2+3 = 5
        "-*234",      // 2*3-4 = 2
        "/+842",      // (8+4)/2 = 6
    };
    
    for (const auto& expr : testCases) {
        try {
            int result = PrefixEvaluator::evaluate(expr);
            std::cout << expr << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << expr << " -> Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}

