/*Given a postfix expression, use a stack to evaluate it and return the result. Postfix, or
Reverse Polish Notation (RPN), is a mathematical notation in which every operator
follows all of its operands.
Sample Input:
● Evaluate "53+82-*".
Sample Output:
● Result: 9
*/

#include<bits/stdc++.h>
using namespace std;
int evaluatePostfix(const std::string& postfix)
{
    stack<int> operandStack;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            operandStack.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            if (operandStack.size() < 2)
            {
                cout << "Invalid postfix expression." <<endl;
                return -1;
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (ch)
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    cout<< "Division by zero is not allowed." <<endl;
                    return -1;
                }
                operandStack.push(operand1 / operand2);
                break;
            default:
                cout << "Invalid operator: " << ch << endl;
                return -1;
            }
        }
        else
        {
            cout<< "Invalid character: " << ch << endl;
            return -1;
        }
    }

    if (operandStack.size() != 1)
    {
        cout<< "Invalid postfix expression." <<endl;
        return -1;
    }
    return operandStack.top();
}

int main()
{
    string postfixExpression = "53+82-*";

    int result = evaluatePostfix(postfixExpression);

    if (result != -1)
    {
        cout << "Result: " << result <<endl;
    }
    return 0;
}
