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
        if (top == maxSize - 1)
        {
            cout << "Stack full" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    T pop()
    {
        if (top == -1)
        {
            return T();
        }
        else
        {
            T val = arr[top];
            top--;
            return val;
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
    void clear()
    {
        top = -1;
    }
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    myStack<string> undoStack(100);
    myStack<string> redoStack(100);
    string text = "";
    int choice;
    string input;
    while (true)
    {
        cout << "\nCurrent Text: " << text << endl;
        cout << "1. Type" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter text: ";
            cin >> input;
            undoStack.push(text);
            text = text + input;
            redoStack.clear();
        }
        else if (choice == 2)
        {
            if (text == "")
            {
                cout << "Nothing to delete" << endl;
            }
            else
            {
                undoStack.push(text);
                string newText = "";
                for (int i = 0; text[i] != '\0'; i++)
                {
                    if (text[i + 1] == '\0')
                    {
                        break;
                    }
                    newText = newText + text[i];
                }
                text = newText;
                redoStack.clear();
            }
        }
        else if (choice == 3)
        {
            if (undoStack.isEmpty())
            {
                cout << "Nothing to undo " << endl;
            }
            else
            {
                redoStack.push(text);
                text = undoStack.pop();
            }
        }
        else if (choice == 4)
        {
            if (redoStack.isEmpty())
            {
                cout << "Nothing to redo" << endl;
            }
            else
            {
                undoStack.push(text);
                text = redoStack.pop();
            }
        }
        else if (choice == 5)
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