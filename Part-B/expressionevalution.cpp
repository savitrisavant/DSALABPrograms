#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
// Function to evaluate a postfix expression
int evaluatePostfix(string expr) {
stack<int> stk;
// Iterate over the expression
for (size_t i = 0; i < expr.size(); i++) {
char c = expr[i];
// If the character is a digit, push it onto the stack
if (isdigit(c)) {
stk.push(c - '0');
} else {
// If the character is an operator, pop two operands from the stack,perform
//the operation, and push the result back onto the stack
int operand2 = stk.top();
stk.pop();
int operand1 = stk.top();
stk.pop();
switch (c) {
case '+':
stk.push(operand1 + operand2);
break;
case '-':
stk.push(operand1 - operand2);
break;
case '*':
stk.push(operand1 * operand2);
break;
case '/':
stk.push(operand1 / operand2);
break;
case '^':
stk.push(pow(operand1, operand2));
break;
default:
cout << "Invalid operator\n";
return -1;
}
}
}
// The final result will be at the top of the stack
return stk.top();
}
int main() {
string expr;
cout << "Enter a postfix expression: ";
getline(cin, expr);
int result = evaluatePostfix(expr);
if (result != -1) {
cout << "Result: " << result << endl;
}
return 0;
}
