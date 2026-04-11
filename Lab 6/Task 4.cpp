#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    string data;
    node* next;
};
class queue
{
private:
    node* front;
    node* rear;
public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(string value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue(string value)
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front->data == value)
        {
            node* temp = front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete temp;
            return;
        }
        node* curr = front;
        while (curr->next != NULL && curr->next->data != value)
        {
            curr = curr->next;
        }
        if (curr->next != NULL)
        {
            node* temp = curr->next;
            if (temp == rear)
            {
                rear = curr;
            }
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            cout << "Patient not found" << endl;
        }
    }
    void count()
    {
        node* curr = front;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        cout << "Total patients: " << count << endl;
    }
    void Display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        node* curr = front;
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
    queue obj;
    int choice;
    string name;
    do
    {
        cout << "\n1. Add Patient" << endl;
        cout << "2. Cancel Appointment" << endl;
        cout << "3. Count Patients" << endl;
        cout << "4. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient name: ";
            cin.ignore();
            getline(cin, name);
            obj.enqueue(name);
            break;
        case 2:
            cout << "Enter Patient name to cancel: ";
            cin.ignore();
            getline(cin, name);
            obj.dequeue(name);
            break;
        case 3:
            obj.count();
            break;
        case 4:
            obj.Display();
            break;
        }
    } 
    while (choice != 0);

    return 0;
}