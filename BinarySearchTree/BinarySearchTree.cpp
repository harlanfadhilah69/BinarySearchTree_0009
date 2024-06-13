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


	void search(string element, Node*& parent, Node*& currentNode)
	{
		// This function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && currentNode->info != element)
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empety" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empety" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		//perform the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empety" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree x;
	while (true) {
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3':
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4':
		{
			x.postorder(x.ROOT);
			break;
		}
		case '5':
		{
			return 0;

		default:
		}
		cout << "Pilihan tidak ditemukan" << endl;
		break;

		}
	    }
}
