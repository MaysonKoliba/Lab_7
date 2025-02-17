// Lab7exe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\\Lab7\Lab7.h"
#include <iostream>

int main()
{
	//SciFi Movie Tree Testing
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

	sciFiAscend = sciFiTree->GetAllAscending(sciFiRoot, sciFiAscend);
	sciFiDescend = sciFiTree->GetAllDescending(sciFiRoot, sciFiDescend);

	cout << "<< SciFi Movies Ascending Order >>" << endl;
	for (int i = 0; i < sciFiAscend.size(); i++) {
		cout << to_string(i+1) + " " + sciFiAscend[i]->value << endl;
	}

	cout << endl << "<< SciFi Movies Descending Order >>" << endl;

	for (int i = 0; i < sciFiDescend.size(); i++) {
		cout << to_string(i + 1) + " " + sciFiDescend[i]->value << endl;
	}


	Node* remove1 = sciFiTree->Remove("Star Trek");
	Node* remove2 = sciFiTree->Remove("Galaxy Quest");

	vector<Node*> sciFiAscendRemoved;
	vector<Node*> sciFiDescendRemoved;

	sciFiAscendRemoved = sciFiTree->GetAllAscending(sciFiRoot, sciFiAscendRemoved);
	sciFiDescendRemoved = sciFiTree->GetAllDescending(sciFiRoot, sciFiDescendRemoved);

	cout << endl << "<< SciFi Movies Ascending Order With Nodes Removed >>" << endl;
	for (int i = 0; i < sciFiAscendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + sciFiAscendRemoved[i]->value << endl;
	}

	cout << endl << "<< SciFi Movies Descending Order With Nodes Removed >>" << endl;

	for (int i = 0; i < sciFiDescendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + sciFiDescendRemoved[i]->value << endl;
	}


	//Disney Movie Tree Testing
	BinaryST* disneyTree = new BinaryST();
	Node* node5 = new Node("Cars");
	Node* node6 = new Node("Monsters, Inc");
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

	cout << endl << endl << "<< Disney Movies Ascending Order >>" << endl;
	for (int i = 0; i < disneyAscend.size(); i++) {
		cout << to_string(i + 1) + " " + disneyAscend[i]->value << endl;
	}

	cout << endl << "<< Disney Movies Descending Order >>" << endl;

	for (int i = 0; i < disneyDescend.size(); i++) {
		cout << to_string(i + 1) + " " + disneyDescend[i]->value << endl;
	}

	Node* remove3 = disneyTree->Remove("Monsters, Inc");
	Node* remove4 = disneyTree->Remove("The Incredibles");

	vector<Node*> disneyAscendRemoved;
	vector<Node*> disneyDescendRemoved;

	disneyAscendRemoved = disneyTree->GetAllAscending(disneyRoot, disneyAscendRemoved);
	disneyDescendRemoved = disneyTree->GetAllDescending(disneyRoot, disneyDescendRemoved);

	cout << endl << "<< Disney Movies Ascending Order With Nodes Removed >>" << endl;
	for (int i = 0; i < disneyAscendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + disneyAscendRemoved[i]->value << endl;
	}

	cout << endl << "<< Disney Movies Descending Order With Nodes Removed >>" << endl;

	for (int i = 0; i < disneyDescendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + disneyDescendRemoved[i]->value << endl;
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

	cout << endl << endl << "<< Scary Movies Ascending Order >>" << endl;
	for (int i = 0; i < scaryAscend.size(); i++) {
		cout << to_string(i + 1) + " " + scaryAscend[i]->value << endl;
	}

	cout << endl << "<< Scary Movies Descending Order >>" << endl;

	for (int i = 0; i < scaryDescend.size(); i++) {
		cout << to_string(i + 1) + " " + scaryDescend[i]->value << endl;
	}

	Node* remove5 = scaryTree->Remove("Hocus Pocus");
	Node* remove6 = scaryTree->Remove("Beetlejuice");

	vector<Node*> scaryAscendRemoved;
	vector<Node*> scaryDescendRemoved;

	scaryAscendRemoved = scaryTree->GetAllAscending(scaryRoot, scaryAscendRemoved);
	scaryDescendRemoved = scaryTree->GetAllDescending(scaryRoot, scaryDescendRemoved);

	cout << endl << "<< Scary Movies Ascending Order With Nodes Removed >>" << endl;
	for (int i = 0; i < scaryAscendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + scaryAscendRemoved[i]->value << endl;
	}

	cout << endl << "<< Scary Movies Descending Order With Nodes Removed >>" << endl;

	for (int i = 0; i < scaryDescendRemoved.size(); i++) {
		cout << to_string(i + 1) + " " + scaryDescendRemoved[i]->value << endl;
	}


	delete sciFiTree;
	delete disneyTree;
	delete scaryTree;

	return 0;
}

