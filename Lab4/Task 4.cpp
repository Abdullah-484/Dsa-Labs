#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[100];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }
    bool isEmpty()
    {
        return front > rear;
    }
    bool isFull()
    {
        return rear == 99;
    }
    void enqueue(int ticket_id)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
            return;
        }
        if (ticket_id < 1000 || ticket_id > 9999)
        {
            cout << "Invalid ticket id" << endl;
            return;
        }
        arr[++rear] = ticket_id;
        cout << "Ticket added: " << ticket_id << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No tickets to resolve" << endl;
            return;
        }
        cout << "Resolved ticket: " << arr[front++] << endl;
    }
    void showFront()
    {
        if (isEmpty())
        {
            cout << "No pending tickets" << endl;
            return;
        }
        cout << "Next ticket: " << arr[front] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "No pending tickets" << endl;
            return;
        }
        cout << "Pending tickets: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    int choice, ticket_id;
    do
    {
        cout << endl;
        cout << "1. Add ticket" << endl;
        cout << "2. Resolve ticket" << endl;
        cout << "3. View next ticket" << endl;
        cout << "4. Display all tickets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter 4-digit ticket id: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            q.showFront();
            break;
        }
        case 4:
        {
            q.display();
            break;
        }
        case 5:
        {
            cout << "Exiting system..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }

        }
    }
    while (choice != 5);

    return 0;
}