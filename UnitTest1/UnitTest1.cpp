#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Lab7\Lab7.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//SciFi Movie Tree Tests
		TEST_METHOD(SciFiTreeInsertFindTest)
		{
			BinaryST* sciFiTree = new BinaryST();
			Node* node1 = new Node("Star Wars");
			Node* node2 = new Node("Star Trek");
			Node* node3 = new Node("Space Balls");
			Node* node4 = new Node("Galaxy Quest");

			//Tests insertion function
			sciFiTree->Insert(node1);
			sciFiTree->Insert(node2);
			sciFiTree->Insert(node3);
			sciFiTree->Insert(node4);

			//tests Find function
			Node* findNode = sciFiTree->Find("Space Balls");

			//tests the size function to make sure the 4 nodes were inserted
			Assert::AreEqual(4, sciFiTree->Size());

			//tests Find function
			Assert::IsTrue(findNode->value == "Space Balls");
			Assert::IsTrue(sciFiTree->Find("Avatar") == nullptr);

			delete sciFiTree;
		}

		TEST_METHOD(SciFiTreeRemoveTest)
		{
			BinaryST* sciFiTree = new BinaryST();
			Node* node1 = new Node("Star Wars");
			Node* node2 = new Node("Star Trek");
			Node* node3 = new Node("Space Balls");
			Node* node4 = new Node("Galaxy Quest");

			sciFiTree->Insert(node1);
			sciFiTree->Insert(node2);
			sciFiTree->Insert(node3);
			sciFiTree->Insert(node4);

			//tests remove function
			Node* remove1 = sciFiTree->Remove("Star Trek");
			Node* remove2 = sciFiTree->Remove("Galaxy Quest");

			//tests getRoot function and makes sure the tree was reconnected after removing nodes
			Assert::IsTrue(sciFiTree->getRoot()->leftChild->value == "Space Balls");
			Assert::IsTrue(sciFiTree->getRoot()->leftChild->leftChild == nullptr);

			//checks the Size function to make sure the size of the tree decreased after removing nodes
			Assert::AreEqual(2, sciFiTree->Size());

			delete sciFiTree;
			delete remove1;
			delete remove2;
		}

		TEST_METHOD(SciFiTreeEmptyTest)
		{
			BinaryST* sciFiTree = new BinaryST();
			Node* node1 = new Node("Star Wars");
			Node* node2 = new Node("Star Trek");
			Node* node3 = new Node("Space Balls");
			Node* node4 = new Node("Galaxy Quest");

			sciFiTree->Insert(node1);
			sciFiTree->Insert(node2);
			sciFiTree->Insert(node3);
			sciFiTree->Insert(node4);

			//checks the getPrevious function
			Node* previous1 = sciFiTree->getPrevious("Star Trek");
			Node* previous2 = sciFiTree->getPrevious("Galaxy Quest");

			//makes sure the nodes that were returned from the getPrevious function
			//were the right nodes
			Assert::IsTrue(previous1->value == "Star Wars");
			Assert::IsTrue(previous2->value == "Space Balls");

			//checks the Empty function
			sciFiTree->EmptyTree(sciFiTree->getRoot());

			//makes sure the size of the tree is 0 after using the Empty Function
			Assert::AreEqual(sciFiTree->Size(), 0);

			//these tests are completed for the other test trees as well
		}


		//Disney Movie Tree Tests
		TEST_METHOD(DisneyTreeInsertFindTest)
		{
			BinaryST* disneyTree = new BinaryST();
			Node* node5 = new Node("Cars");
			Node* node6 = new Node("Monsters, Inc");
			Node* node7 = new Node("The Incredibles");
			Node* node8 = new Node("Wall-E");

			disneyTree->Insert(node5);
			disneyTree->Insert(node6);
			disneyTree->Insert(node7);
			disneyTree->Insert(node8);

			Node* findNode = disneyTree->Find("Cars");

			Assert::AreEqual(4,disneyTree->Size());
			Assert::IsTrue(findNode->value == "Cars");
			Assert::IsTrue(disneyTree->Find("Mickey Mouse") == nullptr);

			delete disneyTree;
		}

		TEST_METHOD(DisneyTreeRemoveTest)
		{
			BinaryST* disneyTree = new BinaryST();
			Node* node5 = new Node("Cars");
			Node* node6 = new Node("Monsters, Inc");
			Node* node7 = new Node("The Incredibles");
			Node* node8 = new Node("Wall-E");

			disneyTree->Insert(node5);
			disneyTree->Insert(node6);
			disneyTree->Insert(node7);
			disneyTree->Insert(node8);

			Node* remove1 = disneyTree->Remove("Monsters, Inc");
			Node* remove2 = disneyTree->Remove("Wall-E");

			Assert::IsTrue(disneyTree->getRoot()->rightChild->value == "The Incredibles");
			Assert::IsTrue(disneyTree->getRoot()->rightChild->rightChild == nullptr);
			Assert::AreEqual(2, disneyTree->Size());

			delete disneyTree;
			delete remove1;
			delete remove2;
		}

		TEST_METHOD(DisneyTreeEmptyTest)
		{
			BinaryST* disneyTree = new BinaryST();
			Node* node5 = new Node("Cars");
			Node* node6 = new Node("Monsters, Inc");
			Node* node7 = new Node("The Incredibles");
			Node* node8 = new Node("Wall-E");

			disneyTree->Insert(node5);
			disneyTree->Insert(node6);
			disneyTree->Insert(node7);
			disneyTree->Insert(node8);

			Node* previous1 = disneyTree->getPrevious("The Incredibles");
			Node* previous2 = disneyTree->getPrevious("Wall-E");

			Assert::IsTrue(previous1->value == "Monsters, Inc");
			Assert::IsTrue(previous2->value == "The Incredibles");

			disneyTree->EmptyTree(disneyTree->getRoot());

			Assert::AreEqual(disneyTree->Size(), 0);
		}


		//Scary Movie Tree Tests
		TEST_METHOD(ScaryTreeInsertFindTest)
		{
			BinaryST* scaryTree = new BinaryST();
			Node* node9 = new Node("Halloween");
			Node* node10 = new Node("A Nightmare On Elm Street");
			Node* node11 = new Node("Hocus Pocus");
			Node* node12 = new Node("Beetlejuice");

			scaryTree->Insert(node9);
			scaryTree->Insert(node10);
			scaryTree->Insert(node11);
			scaryTree->Insert(node12);

			Node* findNode = scaryTree->Find("Hocus Pocus");

			Assert::AreEqual(4, scaryTree->Size());
			Assert::IsTrue(findNode->value == "Hocus Pocus");
			Assert::IsTrue(scaryTree->Find("Scream") == nullptr);

			delete scaryTree;
		}

		TEST_METHOD(ScaryTreeRemoveTest)
		{
			BinaryST* scaryTree = new BinaryST();
			Node* node9 = new Node("Halloween");
			Node* node10 = new Node("A Nightmare On Elm Street");
			Node* node11 = new Node("Hocus Pocus");
			Node* node12 = new Node("Beetlejuice");

			scaryTree->Insert(node9);
			scaryTree->Insert(node10);
			scaryTree->Insert(node11);
			scaryTree->Insert(node12);

			Node* remove1 = scaryTree->Remove("Hocus Pocus");
			Node* remove2 = scaryTree->Remove("A Nightmare On Elm Street");

			Assert::IsTrue(scaryTree->getRoot()->rightChild == nullptr);
			Assert::IsTrue(scaryTree->getRoot()->leftChild->value == "Beetlejuice");
			Assert::AreEqual(2, scaryTree->Size());

			delete scaryTree;
			delete remove1;
			delete remove2;
		}

		TEST_METHOD(ScaryTreeEmptyTest)
		{
			BinaryST* scaryTree = new BinaryST();
			Node* node9 = new Node("Halloween");
			Node* node10 = new Node("A Nightmare On Elm Street");
			Node* node11 = new Node("Hocus Pocus");
			Node* node12 = new Node("Beetlejuice");

			scaryTree->Insert(node9);
			scaryTree->Insert(node10);
			scaryTree->Insert(node11);
			scaryTree->Insert(node12);

			Node* previous1 = scaryTree->getPrevious("Beetlejuice");
			Node* previous2 = scaryTree->getPrevious("Hocus Pocus");

			Assert::IsTrue(previous1->value == "A Nightmare On Elm Street");
			Assert::IsTrue(previous2->value == "Halloween");

			scaryTree->EmptyTree(scaryTree->getRoot());

			Assert::AreEqual(scaryTree->Size(), 0);
		}
	};
}
