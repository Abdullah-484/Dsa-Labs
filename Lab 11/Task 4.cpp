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
	//recursive function to find minimum value in BST
	node* findMin(node* curr)
	{
		//if tree is empty or left child becomes NULL
		//current node contains minimum value
		if (curr == NULL || curr->LTree == NULL)
		{
			return curr;
		}
		//moving continuously toward left subtree
		return findMin(curr->LTree);
	}
	//recursive function to find maximum value in BST
	node* findMax(node* curr)
	{
		//if tree is empty or right child becomes NULL
		//current node contains maximum value
		if (curr == NULL || curr->RTree == NULL)
		{
			return curr;
		}
		//moving continuously toward right subtree
		return findMax(curr->RTree);
	}
};

int main()
{
	BST obj;
	obj.create();

	//minNode and maxNode pointers store value from findMin and findMax function b/c it return pointer
	node* minNode = obj.findMin(obj.root);
	node* maxNode = obj.findMax(obj.root);
	//displaying minimum value
	if (minNode != NULL)
	{
		cout << "minimum: " << minNode->data << endl;
	}
	//displaying maximum value
	if (maxNode != NULL)
	{
		cout << "maximum: " << maxNode->data << endl;
	}

	return 0;
}