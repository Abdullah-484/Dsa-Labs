#include<iostream>
#include<string>
using namespace std;

template <typename T>
class myStack
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
            cout << "Parking is full" << endl;
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
            cout << "Parking is empty" << endl;
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
            cout << "No cars parked" << endl;
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
    int getTop() const
    {
        return top;
    }
    T getAt(int index) const
    {
        return arr[index];
    }
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    myStack<string> parking(8);
    int choice;
    string car;
    while (true)
    {
        cout << "\n1. Park Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. Display Cars" << endl;
        cout << "4. Total Cars" << endl;
        cout << "5. Search Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
        }
        else if (choice == 2)
        {
            if (parking.isEmpty())
            {
                cout << "Parking is empty" << endl;
            }
            else
            {
                cout << "Enter car number to remove: ";
                cin >> car;
                myStack<string> temp(8);
                bool found = false;
                while (!parking.isEmpty())
                {
                    string x = parking.pop();
                    if (x == car)
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        temp.push(x);
                    }
                }
                if (found == false)
                {
                    cout << "Car not found" << endl;
                }
                else
                {
                    cout << "Car removed" << endl;
                }
                while (!temp.isEmpty())
                {
                    parking.push(temp.pop());
                }
            }
        }
        else if (choice == 3)
        {
            parking.display();
        }
        else if (choice == 4)
        {
            cout << "Total cars: " << parking.getTop() + 1 << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter car number to search: ";
            cin >> car;
            bool found = false;
            for (int i = 0; i <= parking.getTop(); i++)
            {
                if (parking.getAt(i) == car)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                cout << "Car found" << endl;
            }
            else
            {
                cout << "Car not found" << endl;
            }
        }
        else if (choice == 6)
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