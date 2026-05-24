#include <iostream>
using namespace std;

class node
{
public:
	node* LTree, * RTree;
	int data;
};
class BST
{
public:
	node* root;

	BST()
	{
		root = NULL;
	}
	void create()
	{
		node* p;
		int value, c;
		//taking total number of nodes from user
		cout << "enter no of nodes: ";
		cin >> c;
		//checking if entered nodes are valid if -ve or 0 return
		if (c <= 0)
		{
			return;
		}
		//loop runs according to total nodes
		for (int i = 0; i < c; i++)
		{
			//creating root node if tree is empty
			if (root == NULL)
			{
				root = new node;
				cout << "enter value of root node" << endl;
				cin >> root->data;
				root->LTree = NULL;
				root->RTree = NULL;
			}
			else
			{
				//starting pointer from root
				p = root;
				cout << "enter value of node" << endl;
				cin >> value;
				//finding correct position for new node
				while (true)
				{
					//moving toward left subtree
					if (value < p->data)
					{
						//inserting node if left side is empty
						if (p->LTree == NULL)
						{
							p->LTree = new node;
							p = p->LTree;
							p->data = value;
							p->LTree = NULL;
							p->RTree = NULL;
							cout << value << " entered in left to its parent" << endl;
							break;
						}
						else
						{
							//moving further left
							p = p->LTree;
						}
					}
					//moving toward right subtree
					else if (value >= p->data)
					{
						//inserting node if right side is empty
						if (p->RTree == NULL)
						{
							p->RTree = new node;
							p = p->RTree;
							p->data = value;
							p->LTree = NULL;
							p->RTree = NULL;
							cout << value << " entered in right to its parent" << endl;
							break;
						}
						else
						{
							//moving further right
							p = p->RTree;
						}
					}
				}
			}
		}
	}
	node* search(node* curr, int num)
	{
		//if current node becomes NULL value does not exist
		if (curr == NULL)
		{
			return NULL;
		}
		//if value matches with current node return node
		if (curr->data == num)
		{
			return curr;
		}
		//if value is smaller move toward left subtree
		else if (num < curr->data)
		{
			return search(curr->LTree, num);
		}
		//if value is greater move toward right subtree
		else
		{
			return search(curr->RTree, num);
		}
	}
};

int main()
{
	BST obj;
	obj.create();
	int value;
	cout << "\nenter value to search" << endl;
	cin >> value;
	//as search function return pointer so value is stored in temp pointer
	node* temp = obj.search(obj.root, value);
	//if and else checking value found or not found
	if (temp == NULL)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "found" << endl;
	}

	return 0;
}