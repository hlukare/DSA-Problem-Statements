#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class ExpressionConverter {
public:
    string infixToPrefix(const string& infix);
    string prefixToPostfix(const string& prefix);
    string prefixToInfix(const string& prefix);
    string postfixToInfix(const string& postfix);
    string postfixToPrefix(const string& postfix);

private:
    bool isOperator(char c);
    bool isOperand(char c);
    int precedence(char op);
};

string ExpressionConverter::infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (int i = infix.length() - 1; i >= 0; i--) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        } else if (isOperand(infix[i])) {
            operands.push(string(1, infix[i]));
        } else if (isOperator(infix[i])) {
            while (!operators.empty() && precedence(operators.top()) > precedence(infix[i])) {
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                operands.push(operators.top() + op1 + op2);
                operators.pop();
            }
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            operators.push(infix[i]);
        } else if (infix[i] == '(') {
            while (!operators.empty() && operators.top() != ')') {
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                operands.push(operators.top() + op1 + op2);
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top(); operands.pop();
        string op1 = operands.top(); operands.pop();
        operands.push(operators.top() + op1 + op2);
        operators.pop();
    }

    return operands.top();
}

string ExpressionConverter::prefixToPostfix(const string& prefix) {
    stack<string> operands;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (prefix[i] == ' ' || prefix[i] == '\t') {
            continue;
        } else if (isOperand(prefix[i])) {
            operands.push(string(1, prefix[i]));
        } else if (isOperator(prefix[i])) {
            string op1 = operands.top(); operands.pop();
            string op2 = operands.top(); operands.pop();
            operands.push(op1 + op2 + prefix[i]);
        }
    }

    return operands.top();
}

string ExpressionConverter::prefixToInfix(const string& prefix) {
    stack<string> operands;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (prefix[i] == ' ' || prefix[i] == '\t') {
            continue;
        } else if (isOperand(prefix[i])) {
            operands.push(string(1, prefix[i]));
        } else if (isOperator(prefix[i])) {
            string op1 = operands.top(); operands.pop();
            string op2 = operands.top(); operands.pop();
            operands.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }

    return operands.top();
}

string ExpressionConverter::postfixToInfix(const string& postfix) {
    stack<string> operands;

    for (char c : postfix) {
        if (c == ' ' || c == '\t') {
            continue;
        } else if (isOperand(c)) {
            operands.push(string(1, c));
        } else if (isOperator(c)) {
            string op2 = operands.top(); operands.pop();
            string op1 = operands.top(); operands.pop();
            operands.push("(" + op1 + c + op2 + ")");
        }
    }

    return operands.top();
}

string ExpressionConverter::postfixToPrefix(const string& postfix) {
    stack<string> operands;

    for (char c : postfix) {
        if (c == ' ' || c == '\t') {
            continue;
        } else if (isOperand(c)) {
            operands.push(string(1, c));
        } else if (isOperator(c)) {
            string op2 = operands.top(); operands.pop();
            string op1 = operands.top(); operands.pop();
            operands.push(c + op1 + op2);
        }
    }

    return operands.top();
}

bool ExpressionConverter::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool ExpressionConverter::isOperand(char c) {
    return isalnum(c);
}

int ExpressionConverter::precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int main() {
    ExpressionConverter converter;
    int choice;
    string expression, result;

    do {
        cout << "Expression Conversion and Evaluation Menu\n";
        cout << "1. Infix to Prefix\n";
        cout << "2. Prefix to Postfix\n";
        cout << "3. Prefix to Infix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Postfix to Prefix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                result = converter.infixToPrefix(expression);
                cout << "Prefix expression: " << result << endl;
                break;
            case 2:
                cout << "Enter prefix expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                result = converter.prefixToPostfix(expression);
                cout << "Postfix expression: " << result << endl;
                break;
            case 3:
                cout << "Enter prefix expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                result = converter.prefixToInfix(expression);
                cout << "Infix expression: " << result << endl;
                break;
            case 4:
                cout << "Enter postfix expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                result = converter.postfixToInfix(expression);
                cout << "Infix expression: " << result << endl;
                break;
            case 5:
                cout << "Enter postfix expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                result = converter.postfixToPrefix(expression);
                cout << "Prefix expression: " << result << endl;
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
