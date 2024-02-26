/*Implement a function to sort a stack such that the smallest items are on the top. You
may use an additional temporary stack, but you should not copy the elements into any
other data structure (e.g., array).
Sample Input:
● Push elements 3, 1, 4, 2 into an unsorted stack and sort it.
Sample Output:
● Sorted Stack: 1, 2, 3, 4
These tasks progressively increase in complexity and cover a wide range of stack
applications, from basic operations to more complex algorithms and data structure
manipulations.
*/

#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int>& inputStack)
{
    stack<int> tempStack;

    while (!inputStack.empty())
    {
        int currentElement = inputStack.top();
        inputStack.pop();
        while (!tempStack.empty() && tempStack.top() > currentElement)
        {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(currentElement);
    }
    while (!tempStack.empty())
    {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}
int main()
{
    stack<int> unsortedStack;
    unsortedStack.push(3);
    unsortedStack.push(1);
    unsortedStack.push(4);
    unsortedStack.push(2);
    sortStack(unsortedStack);

    cout << "Sorted Stack: ";
    while (!unsortedStack.empty())
    {
        cout << unsortedStack.top() << " ";
        unsortedStack.pop();
    }
    cout << endl;
    return 0;
}
