#include <iostream>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int d = 0, TreeNode *l = nullptr, TreeNode *r = nullptr)
		: data {d}, left {l}, right {r} {}
};

class OurSet
{
private:
	TreeNode *root;
	unsigned int numItems;
public:
	OurSet()
	{
		root = nullptr;
		numItems = 0;
	}

	void add(int value)
	{
		addHelper(value, root);
	}

	void addHelper(int value, TreeNode *&curNode)
	{
		if (curNode == nullptr) {
			curNode = new TreeNode(value);
			numItems++;
		}
		else {
			if (value > curNode->data)
				addHelper(value, curNode->right);
			else if (value < curNode->data)
				addHelper(value, curNode->left);
		}
	}

	bool constains(int value) { return containsHelper(value, root); }

	bool containsHelper(int value, TreeNode *curNode)
	{
		if (curNode == nullptr)   return false;
		if (curNode->data == value)   return true;
		if (value > curNode->data)
			containsHelper(value, curNode->right);
		else
			containsHelper(value, curNode->left);
	}
	// Print in-order tree
	void printOurSet()
	{		
		cout << "{ ";
		printInOrderTree(root);
		cout << "}" << endl;
	}

	void printInOrderTree(TreeNode *curNode)
	{
		if (curNode == nullptr) {
			return;
		}
		printInOrderTree(curNode->left);
		printInOrderTree(curNode->right);
		cout << curNode->data << " ";
	}

	int size() { return numItems; }
	bool isEmpty() { return size() == 0; }

	void clear()
	{
		freeTree(root);
		root = nullptr;
		numItems = 0;
	}
	void freeTree(TreeNode *&tree)
	{
		if (tree == nullptr) return;

		freeTree(tree->left);
		freeTree(tree->right);
		delete tree;
	}

	~OurSet()
	{
		freeTree(root);
	}
};


int main()
{
	OurSet ss;
	ss.add(108);
	ss.add(103);
	ss.add(154);
	ss.add(110);
	ss.add(51);
	ss.add(166);
	ss.add(107);
	ss.add(41);
	ss.add(161);
	ss.add(109);
	ss.add(143);
	ss.add(166);
	ss.add(52);
	ss.add(106);
	cout << ss.size() << endl;
	cout << boolalpha;
	cout << ss.constains(50) << endl;
	ss.printOurSet();
	ss.clear();
	cout << ss.size() << endl;

	ss.printOurSet();
	return 0;
}