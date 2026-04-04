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
    void push(int value)
    {
        arr[++top] = value;
    }
    int pop()
    {
        return arr[top--];
    }
};
class Queue
{
private:
    int arr[100];
    int frontIndex, rear;
public:
    Queue()
    {
        frontIndex = 0;
        rear = -1;
    }
    bool isEmpty()
    {
        return frontIndex > rear;
    }
    void enqueue(int value)
    {
        if (rear == 99)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = value;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }
    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[frontIndex];
    }
    int size()
    {
        return rear - frontIndex + 1;
    }
    void display()
    {
        for (int i = frontIndex; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void reverseK(Queue& q, int k)
{
    if (k <= 1 || q.isEmpty())
    {
        return;
    }
    if (k > q.size())
    {
        k = q.size();
    }
    Stack s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.dequeue());
    }
    while (!s.isEmpty())
    {
        q.enqueue(s.pop());
    }
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++)
    {
        q.enqueue(q.dequeue());
    }
}
int main()
{
    Queue q;
    int n, value, k;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    cout << "Enter queue elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.enqueue(value);
    }
    cout << "Queue: ";
    q.display();
    cout << "how many elements to reverse: " << endl;
    cin >> k;
    reverseK(q, k);
    cout << "Output: ";
    q.display();


    return 0;
}