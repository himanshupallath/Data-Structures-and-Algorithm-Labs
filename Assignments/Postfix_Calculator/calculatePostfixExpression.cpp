#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length) {
    stack<int> result;      // The stack for the answers
    bool check = true;      // bool to check for invalid postfix expression
    // Checks for invalid postfix expression
    if (length <= 2) {
        check = false;
    }
    // One case where having a single element in the postfix expression is valid
    if (length == 1 && isdigit(expression[0][0])) {
        check = true;
    }
    if (check == false) {return 0;}
    // Loops through to calculate the postfix expression
    for (int i = 0; i < length; i++) {
        string current = expression[i];
        // Check to see if its an integer
        if (isdigit(expression[i][0])) {    
            int num = stoi(current);    // Converts the string to an int
            result.push(num);   // pushes int into the stack
        
        // Else if its a symbol
        } else {
            // Gets the top two numbers from the stack
            int num1 = result.top();
            result.pop();
            int num2 = result.top();
            result.pop();

            // does the operations based on the symbol
            if (current == "+") {
                result.push(num1+num2);
            } else if (current == "-") {
                result.push(num2-num1);
            } else if (current == "*") {
                result.push(num1*num2); 
            } else if (current == "/") {
                result.push(num2/num1);
            } else if (current == "%") {
                result.push (num2%num1);
            }
        }
    }
    // This check if at the end of the loop, the answer is the only number on the stack
    if (result.size() > 1) {    
        return 0;   // If there is more than 2 numbers then return 0;
    }
    return result.top();    // Returns the answer
}
