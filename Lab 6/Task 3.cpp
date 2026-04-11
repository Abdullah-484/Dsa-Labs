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
    void insertAtPos(int value, int pos)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (pos == 1)
        {
            temp->next = head;
            head = temp;
            return;
        }
        node* curr = head;
        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            delete temp;
            return;
        }
        temp->next = curr->next;
        curr->next = temp;
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
    void searchEle(int value)
    {
        node* curr = head;
        int pos = 1;

        while (curr != NULL)
        {
            if (curr->data == value)
            {
                cout << "Element found at position " << pos << endl;
                return;
            }
            curr = curr->next;
            pos++;
        }

        cout << "Element not found" << endl;
    }

    void count()
    {
        node* curr = head;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        cout << "Total nodes= " << count << endl;
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
    int choice, value, pos;
    do
    {
        cout << "\n1. Insert at Position" << endl;
        cout << "2. Delete by Value" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Count Nodes" << endl;
        cout << "5. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            obj.insertAtPos(value, pos);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            obj.deleteVal(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            obj.searchEle(value);
            break;

        case 4:
            obj.count();
            break;

        case 5:
            obj.Display();
            break;
        }

    } 
    while (choice != 0);

    return 0;
}
