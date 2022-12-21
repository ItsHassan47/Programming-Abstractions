#include "Stack.h"

using namespace std;

int main()
{
	cout << "This simple program uses a linked-list based stack " << endl
		<< "to reverse the input provided by a user!" << endl << endl;

	Stack stack;
	while (true) {
		int input = 0;
		cout << "Please enter a number (-1 to stop entering): ";
		cin >> input;
		if (input == -1) break;
		stack.push(input);
	}

	while (!stack.isEmpty()) {
		cout << stack.pop() << endl;
	}


	return 0;
}