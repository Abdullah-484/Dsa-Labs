#include<iostream>
#include<string>
using namespace std;

template <typename T>
class AbstractStack
{
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T topElement() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void display() const = 0;
    virtual ~AbstractStack() {}
};
template <typename T>
class myStack : public AbstractStack<T>
{
private:
    T* arr;
    int top;
    int maxSize;
public:
    myStack(int size)
    {
        maxSize = size;
        arr = new T[maxSize];
        top = -1;
    }
    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        else
        {
            T val = arr[top];
            top--;
            return val;
        }
    }
    T topElement() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull() const
    {
        if (top == maxSize - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    myStack<int> s(5);
    int choice;
    int value;
    while (true)
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2)
        {
            int v = s.pop();
            cout << "Popped: " << v << endl;
        }
        else if (choice == 3)
        {
            cout << "Top element: " << s.topElement() << endl;
        }
        else if (choice == 4)
        {
            if (s.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
        }
        else if (choice == 5)
        {
            if (s.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
        }
        else if (choice == 6)
        {
            s.display();
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}