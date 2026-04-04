#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int id[100];
    string address[100];
    int startTime[100], endTime[100];
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
    void enqueue(int pid, string addr, int start, int end)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
            return;
        }
        rear++;
        id[rear] = pid;
        address[rear] = addr;
        startTime[rear] = start;
        endTime[rear] = end;
        cout << "Package added" << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        cout << "Delivered package id = " << id[front] << endl;
        front++;
        if (isEmpty())
        {
            front = 0;
            rear = -1;
        }
    }
    void showFront()
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        cout << "Front package id = " << id[front] << endl;
        cout << "Address = " << address[front] << endl;
        cout << "Time window = " << startTime[front] << " to " << endTime[front] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        cout << "All packages = " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << "Id = " << id[i] << " Address = " << address[i] << " Time = " << startTime[i] << "-" << endTime[i] << endl;
        }
    }
    void timeToDeliver(int currentTime)
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        if (currentTime > endTime[front])
        {
            cout << "Package expired, skipping ID = " << id[front] << endl;
            front++;
        }
        else if (currentTime >= startTime[front] && currentTime <= endTime[front])
        {
            cout << "Package can be delivered now." << endl;
            dequeue();
        }
        else
        {
            cout << "Wait! Delivery window starts at = " << startTime[front] << endl;
        }
        if (isEmpty())
        {
            front = 0;
            rear = -1;
        }
    }
};
int main()
{
    Queue q;
    int choice, pid, start, end, currentTime;
    string addr;
    do
    {
        cout << endl;
        cout << "1. Add package" << endl;
        cout << "2. Deliver package" << endl;
        cout << "3. View front package" << endl;
        cout << "4. Display all packages" << endl;
        cout << "5. Check time and deliver" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice = ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter id = ";
            cin >> pid;
            cin.ignore();
            cout << "Enter address = ";
            getline(cin, addr);
            cout << "Enter start time = ";
            cin >> start;
            cout << "Enter end time = ";
            cin >> end;
            q.enqueue(pid, addr, start, end);
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
            cout << "Enter current time = ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
            break;
        }
        case 6:
        {
            cout << "Exiting system..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    } 
    while (choice != 6);
    
    return 0;
}