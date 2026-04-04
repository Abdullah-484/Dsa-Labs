#include <iostream>
using namespace std;

class Queue
{
private:
	string arr[100];
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
	void enqueue(string document)
	{
		if (isFull())
		{
			cout << "Queue full" << endl;
			return;
		}
		arr[++rear] = document;
		cout << "Document added: " << document << endl;
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "No documents to print" << endl;
			return;
		}
		cout << "Printing document: " << arr[front++] << endl;
	}
	void showFront()
	{
		if (isEmpty())
		{
			cout << "No documents in queue" << endl;
			return;
		}
		cout << "Next document: " << arr[front] << endl;
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "No documents in queue" << endl;
			return;
		}
		cout << "Pending documents: ";
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
	int choice;
	string document;
	do
	{
		cout << endl;
		cout << "1. Add document" << endl;
		cout << "2. Print document" << endl;
		cout << "3. View next document" << endl;
		cout << "4. Display all documents" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter document name: ";
			cin >> document;
			q.enqueue(document);
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
			cout << "Shutting down printer system..." << endl;
			break;
		}
		default:
		{
			cout << "Invalid choice" << endl;
		}
		}
	} 
	while(choice != 5);
	
	
	return 0;
}