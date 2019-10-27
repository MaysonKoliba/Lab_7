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
BinaryST::~BinaryST() {

	EmptyTree();
}

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


Node* BinaryST::Find(string value) {
	
	Node* temp = this->root;
	bool stop = false;

	if (temp->value == value) {
		return temp;
	}

	while (stop == false) {

		if (value.compare(temp->value) > 0) {

			if (temp->rightChild->value == value) {
				temp = temp->rightChild;
				stop = true;
				return temp;
			}
			else {
				temp = temp->rightChild;
			}
		}
		else if (value.compare(temp->value) < 0) {

			if (temp->leftChild->value == value) {
				temp = temp->leftChild;
				stop = true;
				return temp;
			}
			else {
				temp = temp->leftChild;
			}
		}
	}

	return nullptr;
};


Node* BinaryST::getRoot() {
	return root;
}

int BinaryST::Size() {

	return nodeCount;
};

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


void BinaryST::EmptyTree() {

	for (int i = 0; i < tree.size(); i++) {
		delete tree[i];
	}

};

Node* BinaryST::minValueNode(Node* node)
{
	Node* current = node;

	while (current && current->leftChild != nullptr)
		current = current->leftChild;

	return current;
}

Node* BinaryST::getPrevious(string value) {

	Node* temp = this->root;
	bool stop = false;

	if (temp->value == value) {
		return temp;
	}

	while (stop == false) {

		if (value.compare(temp->value) > 0) {

			if (temp->rightChild->value == value) {
				stop = true;
				return temp;
			}
			else {
				temp = temp->rightChild;
			}
		}
		else if (value.compare(temp->value) < 0) {

			if (temp->leftChild->value == value) {
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


Node* BinaryST::Remove(string value) {

	Node* targetNode = this->Find(value);
	Node* previousNode = getPrevious(targetNode->value);

	if (targetNode->leftChild != nullptr && targetNode->rightChild != nullptr) {
		if (previousNode->leftChild->value == targetNode->value) {
			previousNode->leftChild = targetNode->leftChild;
			previousNode->leftChild->leftChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
		else if (previousNode->rightChild->value == targetNode->value) {
			previousNode->rightChild = targetNode->leftChild;
			previousNode->rightChild->leftChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
	}
	else if (targetNode->leftChild != nullptr) {
		if (previousNode->leftChild->value == targetNode->value) {
			previousNode->leftChild = targetNode->leftChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
		else if (previousNode->rightChild->value == targetNode->value) {
			previousNode->rightChild = targetNode->leftChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
	}
	else if (targetNode->rightChild != nullptr) {
		if (previousNode->leftChild->value == targetNode->value) {
			previousNode->leftChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
		else if (previousNode->rightChild->value == targetNode->value) {
			previousNode->rightChild = targetNode->rightChild;
			targetNode->leftChild = nullptr;
			targetNode->rightChild = nullptr;
		}
	}

	return targetNode;
};