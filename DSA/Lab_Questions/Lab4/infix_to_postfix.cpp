/*
Design and implement a program to convert an infix expression to its corresponding postfix expression using a stack. The program should support expressions containing operators '+', '-', '*', '/', and parentheses '(' and ')' and provide a mechanism to handle operator precedence and parentheses.
Example Testcases
Input:
A*B+C
Output:
AB*C+

Input:
A+B*C-D/E
Output:
ABC*+DE/-

Input:
(A+B)*(C-D)

Output:
AB+CD-*
*/

//Solution Template:
#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(char value) {
        
    }

    char pop() {
        
    }

    char peek() const {
        
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};


void infixToPostfix(const char* infix, char* postfix) {
    
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}

//Solution:
#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) return '\0';
        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() const {
        if (isEmpty()) return '\0';
        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stk;
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {  // Operand → directly append
            postfix[j++] = c;
        }
        else if (c == '(') {
            stk.push(c);
        }
        else if (c == ')') {
            while (!stk.isEmpty() && stk.peek() != '(') {
                postfix[j++] = stk.pop();
            }
            stk.pop(); // remove '('
        }
        else { // Operator
            while (!stk.isEmpty() && precedence(stk.peek()) >= precedence(c)) {
                postfix[j++] = stk.pop();
            }
            stk.push(c);
        }
    }

    // Pop remaining operators
    while (!stk.isEmpty()) {
        postfix[j++] = stk.pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}
