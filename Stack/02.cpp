/*Extend your stack operations to include a function that checks if a given string of
parentheses is balanced. A string is balanced if each open parenthesis is matched with
a closing parenthesis in the correct order.
Sample Input:
● Check balance for "(()())".
Sample Output:
● Is balanced: Yes
*/

#include <bits/stdc++.h>
using namespace std;
bool isBalanced(const string& parentheses)
{
    stack<char> charStack;
    for (char ch : parentheses)
    {
        if (ch == '(')
        {
            charStack.push(ch);
        }
        else if (ch == ')')
        {
            if (charStack.empty() || charStack.top() != '(')
            {
                return false;
            }
            charStack.pop();
        }
    }
    return charStack.empty();
}
int main()
{
    string input = "(()())";
    if (isBalanced(input))
    {
        cout << "Is balanced: Yes" << endl;
    }
    else
    {
        cout << "Is balanced: No" << endl;
    }
    return 0;
}
