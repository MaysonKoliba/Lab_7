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
		
		TEST_METHOD(SciFiTreeInsertFindTest)
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

			Node* findNode = sciFiTree->Find("Space Balls");

			Assert::AreEqual(4, sciFiTree->Size());
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

			Node* remove1 = sciFiTree->Remove("Star Trek");
			Node* remove2 = sciFiTree->Remove("Galaxy Quest");

			Assert::IsTrue(sciFiTree->getRoot()->leftChild->value == "Space Balls");
			Assert::IsTrue(sciFiTree->getRoot()->leftChild->leftChild == nullptr);
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

			Node* previous1 = sciFiTree->getPrevious("Star Trek");
			Node* previous2 = sciFiTree->getPrevious("Galaxy Quest");

			Assert::IsTrue(previous1->value == "Star Wars");
			Assert::IsTrue(previous2->value == "Space Balls");

			sciFiTree->EmptyTree(sciFiTree->getRoot());

			Assert::AreEqual(sciFiTree->Size(), 0);
		}
	};
}
