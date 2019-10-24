// Lab7.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
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

//Binary Search Tree destructor
BinaryST::~BinaryST() {

	EmptyTree();
}


void BinaryST::Insert(Node* node) {

	if (tree.empty()) {
		tree.push_back(node);
	}
	else{

		Node* temp = tree[0];
		bool stop = false;

		while (stop == false) {

			if (node->value.compare(temp->value) > 0) {

				if (temp->rightChild == nullptr) {
					temp->rightChild = node;
					tree.push_back(node);
					stop = true;
				}
				else {
					temp = temp->rightChild;
				}
			}
			else if(node->value.compare(temp->value) < 0) {

				if (temp->leftChild == nullptr) {
					temp->leftChild = node;
					tree.push_back(node);
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
	Node* test = nullptr;

	return test;
};


int BinaryST::Size() {

	return 0;
};


vector<Node*> BinaryST::GetAllAscending() {

	bool sorted = false;
	vector<Node*> newTree = tree;
	Node* temp;

	for (int i = 0; i < newTree.size(); i++) {
		if (sorted) {
			break;
		}
		else {
			sorted = true;
			for (int j = 0; j < newTree.size() - 1; j++) {
				if (newTree[j]->value.compare(newTree[j+1]->value) > 0) {
					temp = newTree[j + 1];
					newTree[j + 1] = newTree[j];
					newTree[j] = temp;
					sorted = false;
				}
			}
		}
	}

	return newTree;
};


vector<Node*> BinaryST::GetAllDescending() {
	vector<Node*> testVector = tree;

	return testVector;
};


void BinaryST::EmptyTree() {

	for (int i = 0; i < tree.size(); i++) {
		delete tree[i];
	}

};


void BinaryST::Remove() {};