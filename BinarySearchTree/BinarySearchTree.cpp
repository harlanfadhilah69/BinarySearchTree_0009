#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; //Initializing ROOT to null
	}

	void insert(string element) // Insert a node in the binary search treee
	{
		Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for the new node
		newNode->info = element; // asign value to the data field of the new data
		newNode->leftchild = nullptr; // Make the left child of the new node point to NULL
		newNode->rightchild = nullptr; // Make the right child of the new data point to NULL

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // Locate the node which the parent of the new node to be inserted

		if (parent == nullptr) // if the parent is NULL (tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; // Exit
		}

		if (element < parent->info) //if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode; //Make the left child of the parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field of the new data is greater than that of the parent
		{
			parent->rightchild = newNode; //Make the right child of the parent to the new node
		}
	}

	

};