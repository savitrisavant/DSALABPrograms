#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
// Function to check if a character is an operator
bool isOperator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Function to get the precedence of an operator
int precedence(char c) {
if (c == '^')
return 3;
else if (c == '*' || c == '/')
return 2;
else if (c == '+' || c == '-')
return 1;
else
return -1; // for '('
}
// Function to convert an infix expression to a postfix expression
string infixToPostfix(string infix) {
stack<char> stk;
string postfix = "";
// Iterate over each character in the infix expression
for (size_t i = 0; i < infix.size(); i++) {
char c = infix[i];
// If the character is an operand (digit or letter), append it to the postfix expression
if (isalnum(c)) {
postfix += c;
} else if (c == '(') { // If the character is '(', push it onto the stack
stk.push(c);
} else if (c == ')') { // If the character is ')', pop and append operators from the stack until
//'(' is encountered
while (!stk.empty() && stk.top() != '(') {
postfix += stk.top();
stk.pop();
}
if (!stk.empty())
stk.pop(); // Remove '(' from the stack
} else { // If the character is an operator
// Pop and append operators from the stack with higher or equal precedence
while (!stk.empty() && precedence(c) <= precedence(stk.top())) {
postfix += stk.top();
stk.pop();
}
stk.push(c); // Push the current operator onto the stack
}
}
// Append any remaining operators from the stack to the postfix expression
while (!stk.empty()) {
postfix += stk.top();
stk.pop();
}
return postfix;
}
int main() {
string infix;
cout << "Enter an infix expression: ";
getline(cin, infix);
// Convert the infix expression to postfix
string postfix = infixToPostfix(infix);
cout << "Postfix expression: " << postfix << endl;
return 0;
}

