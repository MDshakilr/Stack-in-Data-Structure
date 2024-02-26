/*Implement a function that uses a stack to reverse a given string.
Sample Input:
● Reverse the string "hello".
Sample Output:
● Reversed string: "olleh"
*/

#include <bits/stdc++.h>
using namespace std;

string reverseString(const string& input)
{
    stack<char> charStack;
    for (char ch : input)
    {
        charStack.push(ch);
    }
    string reversedString;
    while (!charStack.empty())
    {
        reversedString += charStack.top();
        charStack.pop();
    }
    return reversedString;
}

int main()
{
    string input = "hello";
    string reversed = reverseString(input);
    cout << "Reversed string: \"" << reversed << "\"" << endl;
    return 0;
}
