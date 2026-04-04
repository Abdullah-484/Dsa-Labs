#include <iostream>
#include <string>

using namespace std;

template <typename T>
class AbstractQueue
{
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front_element() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue : public AbstractQueue<T>
{
private:
    T* data;
    int front;
    int rear;
    int max;
public:
    myQueue(int s)
    {
        max = s;
        data = new T[max];
        front = -1;
        rear = -1;
    }
    ~myQueue()
    {
        delete[] data;
    }
    bool isEmpty() const
    {
        return (front == -1);
    }
    bool isFull() const
    {
        return (rear == max - 1);
    }
    void enQueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        data[rear] = value;
    }
    T deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return T();
        }
        T value = data[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return value;
    }
    T front_element() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return data[front];
    }
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int qSize;
    cout << "Enter the size of the queue: ";
    cin >> qSize;
    myQueue<int> q(qSize);
    int choice;
    int val;
    do
    {
        cout << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> val;
            q.enQueue(val);
            break;
        }
        case 2:
        {
            val = q.deQueue();
            if (val != 0 || !q.isEmpty())
            {
                cout << "Deleted value: " << val << endl;
            }
            break;
        }
        case 3:
        {
            if (!q.isEmpty())
            {
                cout << "Front: " << q.front_element() << endl;
            }
            else
            {
                q.front_element();
            }
            break;
        }
        case 4:
        {
            if (q.isEmpty())
            {
                cout << "Queue is currently empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;
        }
        case 5:
        {
            if (q.isFull())
            {
                cout << "Queue is currently full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;
        }
        case 6:
        {
            q.display();
            break;
        }
        case 7:
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
    
    while (choice != 7);

    return 0;
}