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
    void Display()
    {
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};
int main()
{
    list obj;
    int choice, value;

    do
    {
        cout << "\n1. Create node" << endl;
        cout << "2. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.CreateNode(value);
            break;
        case 2:
            obj.Display();
            break;
        }

    } 
    while (choice != 0);

    return 0;
}
