
/*Modify your stack to support retrieving the minimum element in constant time without
removing it. This will likely require additional storage within your stack structure to keep
track of the minimum elements.
Sample Input:
● Push 5, Push 3, Push 10, Get Min, Pop, Get Min.
Sample Output:
● Minimum element after pushes: 3
● Minimum element after one pop: 5
*/

#include <bits/stdc++.h>
using namespace std;

struct StackWithMin
{
    stack<int> dataStack;
    stack<int> minStack;

    void push(int value)
    {
        dataStack.push(value);
        if (minStack.empty() || value <= minStack.top())
        {
            minStack.push(value);
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        int poppedValue = dataStack.top();
        dataStack.pop();
        if (poppedValue == minStack.top())
        {
            minStack.pop();
        }
        return poppedValue;
    }
    int getMin()
    {
        if (minStack.empty())
        {
            cout << "Stack is empty. No minimum element." << endl;
            return -1;
        }
        return minStack.top();
    }
    bool isEmpty() const
    {
        return dataStack.empty();
    }
};

int main()
{
    StackWithMin myStack;

    myStack.push(5);
    myStack.push(3);
    myStack.push(10);
    cout << "Minimum element after pushes: " << myStack.getMin() << endl;
    myStack.pop();
    cout << "Minimum element after one pop: " << myStack.getMin() << endl;
    return 0;
}
