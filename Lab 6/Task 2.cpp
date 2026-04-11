#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
class list
{
private:
    node* head;
public:
    list()
    {
        head = NULL;
    }
    void CreateNode(int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node* curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void insertAtStart(int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    void deleteVal(int value)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->data == value)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* curr = head;
        while (curr->next != NULL && curr->next->data != value)
        {
            curr = curr->next;
        }

        if (curr->next != NULL)
        {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }
    void Display()
    {
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main()
{
    list obj;
    int choice, value;

    do
    {
        cout << "\n1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete by Value" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.insertAtStart(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            obj.CreateNode(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.deleteVal(value);
            break;

        case 4:
            obj.Display();
            break;
        }

    }
    while (choice != 0);

    return 0;
}
