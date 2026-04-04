#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
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
        return top == 99;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }
};
class QueueStack
{
private:
    Stack stack1, stack2;
public:
    void enqueue(int value)
    {
        stack1.push(value);
        cout << value << " inserted\n";
    }
    void transfer()
    {
        while (!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
    }
    int dequeue()
    {
        if (stack2.isEmpty())
        {
            transfer();
        }
        if (stack2.isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return stack2.pop();
    }
    int front()
    {
        if (stack2.isEmpty())
        {
            transfer();
        }
        if (stack2.isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return stack2.peek();
    }
    void display()
    {
        if (stack1.isEmpty() && stack2.isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Stack temp1 = stack2;
        while (!temp1.isEmpty())
        {
            cout << temp1.pop() << " ";
        }
        Stack temp2;
        Stack temp3 = stack1;
        while (!temp3.isEmpty())
        {
            temp2.push(temp3.pop());
        }
        while (!temp2.isEmpty())
        {
            cout << temp2.pop() << " ";
        }
        cout << endl;
    }
};
int main()
{
    QueueStack q;
    int choice, value;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        }
        case 2:
        {
            value = q.dequeue();
            if (value != -1)
                cout << "Deleted: " << value << endl;
            break;
        }
        case 3:
        {
            value = q.front();
            if (value != -1)
                cout << "Front: " << value << endl;
            break;
        }
        case 4:
        {
            cout << "Queue elements: ";
            q.display();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
        }

        }
    }
    while (choice != 5);

    return 0;
}