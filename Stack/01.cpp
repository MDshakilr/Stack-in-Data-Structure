/*
Define a stack structure that can hold integer values. Implement functions to perform
basic operations:
● push(int): Add an element to the top of the stack.
● pop(): Remove and return the top element from the stack. If the stack is empty,
return a special value or handle the condition gracefully.
Sample Input:
● Push 5.
● Push 10.
● Pop.
Sample Output:
● Top element popped: 10
● Current Stack: 5
*/
#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    static const int MAX_SIZE = 100;
    int item[MAX_SIZE];
    int top;
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow. Cannot push element " << value << endl;
            return;
        }
        item[++top] = value;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. Cannot pop from an empty stack." <<endl;
            return -1;
        }
        return item[top--];
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element to peek." << endl;
            return -1;
        }
        return item[top];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Current Stack: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << item[i] << " ";
        }
        cout <<endl;
    }
};

int main()
{
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    cout << "Top element popped: " << myStack.pop() << endl;
    myStack.display();
    return 0;
}
