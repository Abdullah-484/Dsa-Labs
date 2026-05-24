#include <iostream>
using namespace std;

class node
{
public:
	node* LTree, * RTree;
	int data;
};

class BT
{
public:
	node* root;

	BT()
	{
		root = NULL;
	}
	//below function manually creates a binary tree
	//first root node is created
	//then left and right child nodes are attached
	//total 5 nodes are created manually
	void createTree()
	{
		root = new node;
		root->data = 1;
		root->LTree = new node;
		root->LTree->data = 2;
		root->RTree = new node;
		root->RTree->data = 3;
		root->LTree->LTree = new node;
		root->LTree->LTree->data = 4;
		root->LTree->RTree = new node;
		root->LTree->RTree->data = 5;
		//assigning NULL to remaining child pointers
		root->RTree->LTree = NULL;
		root->RTree->RTree = NULL;
		root->LTree->LTree->LTree = NULL;
		root->LTree->LTree->RTree = NULL;
		root->LTree->RTree->LTree = NULL;
		root->LTree->RTree->RTree = NULL;
	}
	//inorder traversal function
	//left subtree->root->right subtree
	void inorder(node* temp)
	{
		if (temp != NULL)
		{
			inorder(temp->LTree);
			cout << temp->data << endl;
			inorder(temp->RTree);
		}
	}
	//preorder traversal function
	//root->left subtree->right subtree
	void preorder(node* temp)
	{
		if (temp != NULL)
		{
			cout << temp->data << endl;
			preorder(temp->LTree);
			preorder(temp->RTree);
		}
	}
	//postorder traversal function
	//left subtree->right subtree->root
	void postorder(node* temp)
	{
		if (temp != NULL)
		{
			postorder(temp->LTree);
			postorder(temp->RTree);
			cout << temp->data << endl;
		}
	}
};

int main()
{
	BT obj;
	obj.createTree();
	cout << "inorder traversal" << endl;
	obj.inorder(obj.root);
	cout << endl << "preorder traversal" << endl;
	obj.preorder(obj.root);
	cout << endl << "postorder traversal" << endl;
	obj.postorder(obj.root);

	return 0;
}