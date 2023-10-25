#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluatePostfixExpression(const string& expression) {
    stack<int> operands;
    istringstream iss(expression);

    while (!iss.eof()) {
        string token;
        iss >> token;

        if (isdigit(token[0])) {
            int operand = stoi(token);
            operands.push(operand);
        } else if (token == "+") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = operand1 + operand2;
            operands.push(result);
        } else if (token == "-") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = operand1 - operand2;
            operands.push(result);
        } else if (token == "*") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = operand1 * operand2;
            operands.push(result);
        } else if (token == "/") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            if (operand2 != 0) {
                int result = operand1 / operand2;
                operands.push(result);
            } else {
                cerr << "Error: Division by zero." << endl;
                return 0;
            }
        }
    }

    if (!operands.empty()) {
        return operands.top();
    } else {
        cerr << "Error: Invalid postfix expression." << endl;
        return 0;
    }
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression (e.g., 2 3 + 4 *): ";
    getline(cin, postfixExpression);

    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
