#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	int id;
	string name;
	int priority;
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
	void addStudent(int id, string nm, int pr)
	{
		node* temp = new node;
		temp->id = id;
		temp->name = nm;
		temp->priority = pr;
		temp->next = NULL;
		if (head == NULL || pr > head->priority)
		{
			temp->next = head;
			head = temp;
			return;
		}
		node* curr = head;
		while (curr->next != NULL && curr->next->priority >= pr)
		{
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
	}
	void removeStudent(int id)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		node* curr = head;
		node* prev = NULL;
		while (curr != NULL)
		{
			if (curr->id == id)
			{
				if (prev == NULL)
				{
					head = curr->next;
				}
				else
				{
					prev->next = curr->next;
				}
				delete curr;
				cout << "Reservation removed succefully"<< endl;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		cout << "Student not found" << endl;
	}
	void updatePriority(int id, int newPr)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		node* curr = head;
		while (curr != NULL)
		{
			if (curr->id == id)
			{
				string nm = curr->name;
				removeStudent(id);
				addStudent(id, nm, newPr);
				cout << "Priority updated Successfully"<< endl;
				return;
			}
			curr = curr->next;
		}
		cout << "Student not found" << endl;
	}
	void issueBook()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		node* temp = head;
		cout << "Book issued to " << temp->name << " (with ID: " << temp->id << ")" << endl;
		head = head->next;
		delete temp;
	}
	void count()
	{
		if (head == NULL)
		{
			cout << "List is empty (Count = 0)" << endl;
			return;
		}
		int c = 0;
		node* temp = head;
		while (temp != NULL)
		{
			c++;
			temp = temp->next;
		}
		cout << "Total Students: " << c << endl;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		node* curr = head;
		cout << "ID Name BookPriority" << endl;
		while (curr != NULL)
		{
			cout << curr->id << " " << curr->name << " " << curr->priority << endl;
			curr = curr->next;
		}
	}
};
int main()
{
	list book1, book2;
	list* Book = NULL;
	int choice, ch;
	int id, pr;
	string name;
	do
	{
		cout << "\n1. Add Student" << endl;
		cout << "2. Remove Student" << endl;
		cout << "3. Update Priority" << endl;
		cout << "4. Display List" << endl;
		cout << "5. Count Students" << endl;
		cout << "6. Serve Next Student" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice >= 1 && choice <= 6)
		{
			cout << "Select Book (1: Data Structure, 2: Database): ";
			cin >> ch;
			if (ch == 1)
				Book = &book1;
			else if (ch == 2)
				Book = &book2;
			else
			{
				cout << "Invalid book selection" << endl;
				continue;
			}
		}
		switch (choice)
		{
		case 1:
			cout << "Enter Student ID: ";
			cin >> id;
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Priority (1:Research 2:Assign 3:Casual): ";
			cin >> pr;
			Book->addStudent(id, name, pr);
			break;
		case 2:
			cout << "Enter Student ID: ";
			cin >> id;
			Book->removeStudent(id);
			break;
		case 3:
			cout << "Enter Student ID: ";
			cin >> id;
			cout << "Enter New Priority: ";
			cin >> pr;
			Book->updatePriority(id, pr);
			break;
		case 4:
			Book->display();
			break;
		case 5:
			Book->count();
			break;
		case 6:
			Book->issueBook();
			break;
		case 7:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	}
	while (choice != 7);

	return 0;
}