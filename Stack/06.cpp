/*
Challenge yourself by implementing a stack using only two queues. The stack should
support the push and pop operations as defined in Task 1.
Sample Input:
● Push 1, Push 2, Pop.
Sample Output:
● Top element popped: 2
● Current Stack: 1
*/
#include <bits/stdc++.h>
using namespace std;

class StackWithTwoQueues
{
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    void push(int value)
    {
        queue1.push(value);
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        while (queue1.size() > 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int poppedValue = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return poppedValue;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        while (queue1.size() > 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topValue = queue1.front();

        queue2.push(queue1.front());
        queue1.pop();
        swap(queue1, queue2);

        return topValue;
    }
    bool isEmpty() const
    {
        return queue1.empty() && queue2.empty();
    }
};

int main()
{
    StackWithTwoQueues myStack;
    myStack.push(1);
    myStack.push(2);
    cout << "Top element popped: " << myStack.pop() <<endl;
    cout << "Current Stack: " << myStack.top() << endl;

    return 0;
}
