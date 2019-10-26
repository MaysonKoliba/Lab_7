// Lab7exe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\\Lab7\Lab7.h"
#include <iostream>

int main()
{
	//SciFi Show/Movie Tree Testing
	BinaryST* sciFiTree = new BinaryST();
	Node* node1 = new Node("Star Wars");
	Node* node2 = new Node("Star Trek");
	Node* node3 = new Node("Space Balls");
	Node* node4 = new Node("Galaxy Quest");

	sciFiTree->Insert(node1);
	sciFiTree->Insert(node2);
	sciFiTree->Insert(node3);
	sciFiTree->Insert(node4);

	Node* sciFiRoot = sciFiTree->getRoot();
	vector<Node*> sciFiAscend;
	vector<Node*> sciFiDescend;

	Node* node = sciFiTree->Find("Galaxy Quest");
	cout << node->value << endl;
	
	sciFiAscend = sciFiTree->GetAllAscending(sciFiRoot,sciFiAscend);
	sciFiDescend = sciFiTree->GetAllDescending(sciFiRoot, sciFiDescend);

	for (int i = 0; i < sciFiAscend.size(); i++) {
		cout << to_string(i+1) + " " + sciFiAscend[i]->value << endl;
	}

	cout << endl;

	for (int i = 0; i < sciFiDescend.size(); i++) {
		cout << to_string(i + 1) + " " + sciFiDescend[i]->value << endl;
	}


	//Disney Movie Tree Testing
	BinaryST* disneyTree = new BinaryST();
	Node* node5 = new Node("Cars");
	Node* node6 = new Node("Mosters, Inc");
	Node* node7 = new Node("The Incredibles");
	Node* node8 = new Node("Wall-E");

	disneyTree->Insert(node5);
	disneyTree->Insert(node6);
	disneyTree->Insert(node7);
	disneyTree->Insert(node8);

	Node* disneyRoot = disneyTree->getRoot();
	vector<Node*> disneyAscend;
	vector<Node*> disneyDescend;

	disneyAscend = disneyTree->GetAllAscending(disneyRoot,disneyAscend);
	disneyDescend = disneyTree->GetAllDescending(disneyRoot, disneyDescend);

	cout << endl << endl;
	for (int i = 0; i < disneyAscend.size(); i++) {
		cout << to_string(i + 1) + " " + disneyAscend[i]->value << endl;
	}

	cout << endl;

	for (int i = 0; i < disneyDescend.size(); i++) {
		cout << to_string(i + 1) + " " + disneyDescend[i]->value << endl;
	}


	//Scary Movie Tree Testing 
	BinaryST* scaryTree = new BinaryST();
	Node* node9 = new Node("Halloween");
	Node* node10 = new Node("A Nightmare On Elm Street");
	Node* node11 = new Node("Hocus Pocus");
	Node* node12 = new Node("Beetlejuice");

	scaryTree->Insert(node9);
	scaryTree->Insert(node10);
	scaryTree->Insert(node11);
	scaryTree->Insert(node12);

	Node* scaryRoot = scaryTree->getRoot();
	vector<Node*> scaryAscend;
	vector<Node*> scaryDescend;

	scaryAscend = scaryTree->GetAllAscending(scaryRoot,scaryAscend);
	scaryDescend = scaryTree->GetAllDescending(scaryRoot, scaryDescend);

	cout << endl << endl;
	for (int i = 0; i < scaryAscend.size(); i++) {
		cout << to_string(i + 1) + " " + scaryAscend[i]->value << endl;
	}

	cout << endl;

	for (int i = 0; i < scaryDescend.size(); i++) {
		cout << to_string(i + 1) + " " + scaryDescend[i]->value << endl;
	}


	delete sciFiTree;
	delete disneyTree;
	delete scaryTree;

	return 0;
}

