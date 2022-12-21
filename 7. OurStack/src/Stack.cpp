#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}
Stack::~Stack()
{
	while (top != nullptr) {
		Node *temp = top;
		top = top->next;
		delete temp;
	}
}

void printList(Node *list)
{
	while (list != nullptr) {
		std::cout << list->data << std::endl;
		list = list->next;
	}
}

void Stack::push(int value)
{
	Node *newNode = new Node;	// creating a new Node
	newNode->data = value;		// adding value
	newNode->next = top;		// adding the memory address of the Last list top element to newly created list
	top = newNode;				// upgrading the top memory address to the new list we added
	printList(top);
}

int Stack::first() const
{
	if (isEmpty()) {
		std::cerr << "\nCONNOT show top because stack is empty" << std::endl;
		exit(1);
	}
	return top->data;
}

int Stack::pop()
{
	if (isEmpty()) {
		std::cerr << "\nTry to pop from empty stack" << std::endl;
		exit(1);
	}

	int value = top->data;		// storing the top list data in the value
	Node *temp = top;			// stoing top memory address in the temp
	top = top->next;			// upgrading the pointer to point to the next list address
	delete temp;				// deleting temp data because its no longer need since we are poping off the stack
	return value;				// returning the value
}

bool Stack::isEmpty() const
{
	return top == nullptr;
}