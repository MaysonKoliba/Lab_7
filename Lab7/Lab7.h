// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB7_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB7_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB7_EXPORTS
#define LAB7_API __declspec(dllexport)
#else
#define LAB7_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
using namespace std;

class LAB7_API Node {
public:
	string value;
	Node* rightChild;
	Node* leftChild;

	Node();
	Node(string word);
	~Node() {};
};


class LAB7_API BinaryST {
public:

	BinaryST() {};
	~BinaryST();
	void Insert(Node* node);
	Node* Find(string value);
	int Size();
	vector<Node*> GetAllAscending();
	vector<Node*> GetAllDescending();
	void EmptyTree();
	void Remove();

private:
	vector<Node*> tree;
};
