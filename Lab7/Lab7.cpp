// Lab7.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include <iostream>;
#include "Lab7.h"


//Node Constructor
Node::Node()
{
	value = "";
	rightChild = nullptr; 
	leftChild = nullptr;
}

//Node constructor that accpets a word
Node::Node(string word)
{
	value = word;
	rightChild = nullptr;
	leftChild = nullptr;
}

//Binary Search Tree Constructor
BinaryST::BinaryST() {
	nodeCount = 0;
	root = nullptr;
}

//Binary Search Tree Destructor
//Calls the Empty function
BinaryST::~BinaryST() {

	EmptyTree(root);
}

//Inserts a node into the correct place on the tree
//loops through the tree comparing values until it finds the right spot
void BinaryST::Insert(Node* node) {

	if (nodeCount == 0) {
		root = node;
		nodeCount++;
	}
	else{

		Node* temp = root;
		bool stop = false;

		while (stop == false) {

			if (node->value.compare(temp->value) > 0) {

				if (temp->rightChild == nullptr) {
					temp->rightChild = node;
					nodeCount++;
					stop = true;
				}
				else {
					temp = temp->rightChild;
				}
			}
			else if(node->value.compare(temp->value) < 0) {

				if (temp->leftChild == nullptr) {
					temp->leftChild = node;
					nodeCount++;
					stop = true;
				}
				else {
					temp = temp->leftChild;
				}
			}
		}
	}
};

//Finds the node that contains the specified value and returns a pointer to this node
//loops through the tree comparing values until it finds the right node
Node* BinaryST::Find(string value) {
	
	Node* temp = this->root;
	bool stop = false;

	if (temp->value == value) {
		return temp;
	}

	while (stop == false) {

		if (value.compare(temp->value) > 0) {

			if (temp->rightChild == nullptr) {
				return nullptr;
			}
			else if (temp->rightChild->value == value) {
				temp = temp->rightChild;
				return temp;
			}
			else {
				temp = temp->rightChild;
			}
		}
		else if (value.compare(temp->value) < 0) {

			if (temp->leftChild == nullptr) {
				return nullptr;
			}
			else if (temp->leftChild->value == value) {
				temp = temp->leftChild;
				return temp;
			}
			else {
				temp = temp->leftChild;
			}
		}
	}

	return nullptr;
};

//Returns a pointer to the root of the tree
Node* BinaryST::getRoot() {
	return root;
}

//Returns the size of the tree
int BinaryST::Size() {

	return nodeCount;
};

//Returns an array of node pointers in order from smallest to largest
//We used a the inorder algorithm from the book to help us with this function
vector<Node*> BinaryST::GetAllAscending(Node* node, vector<Node*> &treeNodes) {

	if (node == nullptr) {
		return treeNodes;
	};

	if (node->leftChild != nullptr) {
		GetAllAscending(node->leftChild, treeNodes);
	}

	treeNodes.push_back(node);

	if (node->rightChild != nullptr) {
		GetAllAscending(node->rightChild, treeNodes);
	}

	return treeNodes;
};

//Returns an array of node pointers in order from largest to smallest
//This is just the reverse of GetAllAscending
vector<Node*> BinaryST::GetAllDescending(Node* node, vector<Node*>& treeNodes) {
	
	if (node == nullptr) {
		return treeNodes;
	};

	if (node->rightChild != nullptr) {
		GetAllDescending(node->rightChild, treeNodes);
	}

	treeNodes.push_back(node);

	if (node->leftChild != nullptr) {
		GetAllDescending(node->leftChild, treeNodes);
	}

	return treeNodes;
};

//Deletes all of the nodes from the tree
//We used the empty function written in the book to help us with this function
void BinaryST::EmptyTree(Node* node) {

	if (node != nullptr) {
		EmptyTree(node->leftChild);
		EmptyTree(node->rightChild);
		delete node;
		nodeCount--;
	}

	root = nullptr;

};

//Returns a node pointer to the previous node of the specified value
//loops through the tree comparing values until it finds the right node
//and returns the node before it
Node* BinaryST::getPrevious(string value) {

	Node* temp = this->root;
	bool stop = false;

	if (temp->value == value) {
		return temp;
	}

	while (stop == false) {

		if (value.compare(temp->value) > 0) {

			if (temp->rightChild == nullptr) {
				return nullptr;
			}
			else if (temp->rightChild->value == value) {
				stop = true;
				return temp;
			}
			else {
				temp = temp->rightChild;
			}
		}
		else if (value.compare(temp->value) < 0) {

			if (temp->leftChild == nullptr) {
				return nullptr;
			}
			else if (temp->leftChild->value == value) {
				stop = true;
				return temp;
			}
			else {
				temp = temp->leftChild;
			}
		}
	}

	return nullptr;
}

//Removes the node from the tree that contains the specified value
//This function also reconnects the tree to make it legal after delting a node
//This function uses my own algorithm that loops through the tree and checks if the target node
//has other nodes connected to it, and assigns the predecessor to point left child first 
//or the right child if the left child isn't available. In the case of both a left and right child,
//the replacement node is assigned to be the left child, and then the right child is the child of this child
Node* BinaryST::Remove(string value) {

	Node* targetNode = this->Find(value);
	Node* previousNode = getPrevious(targetNode->value);

	if (targetNode->leftChild != nullptr && targetNode->rightChild != nullptr) {
		if (previousNode->leftChild->value == targetNode->value) {
			previousNode->leftChild = targetNode->leftChild;
			previousNode->leftChild->leftChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
			nodeCount--;
		}
		else if (previousNode->rightChild->value == targetNode->value) {
			previousNode->rightChild = targetNode->leftChild;
			previousNode->rightChild->leftChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
			nodeCount--;
		}
	}
	else if (targetNode->leftChild == nullptr && targetNode->rightChild == nullptr) {

		if (previousNode->leftChild != nullptr) {
			if (previousNode->leftChild->value == targetNode->value) {
				previousNode->leftChild = nullptr;
				nodeCount--;
			}
		}

		if (previousNode->rightChild != nullptr) {
			if (previousNode->rightChild->value == targetNode->value) {
				previousNode->rightChild = nullptr;
				nodeCount--;
			}
		}
	}
	else if (targetNode->leftChild != nullptr) {
		if (previousNode->leftChild->value == targetNode->value) {
			previousNode->leftChild = targetNode->leftChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
			nodeCount--;
		}
		else if (previousNode->rightChild->value == targetNode->value) {
			previousNode->rightChild = targetNode->leftChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
			nodeCount--;
		}
	}
	else if (targetNode->rightChild != nullptr) {
		if (previousNode->leftChild != nullptr) {
			if (previousNode->leftChild->value == targetNode->value) {
				previousNode->leftChild = targetNode->rightChild;
				targetNode->leftChild = nullptr;
				targetNode->rightChild = nullptr;
				nodeCount--;
			}
		}
		else if (previousNode->rightChild != nullptr) {
			if (previousNode->rightChild->value == targetNode->value) {
				previousNode->rightChild = targetNode->rightChild;
				targetNode->leftChild = nullptr;
				targetNode->rightChild = nullptr;
				nodeCount--;
			}
		}
	}
	else {
		return nullptr;
	}

	return targetNode;
};