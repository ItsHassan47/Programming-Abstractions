#include <iostream>
#include <stack>

using namespace std;

void printPins(stack<int> source, stack<int> auxiliary, stack<int> destination) {
	cout << "\n========================================================================" << endl;
	if (source.empty())
		cout << "\nsource is empty" << endl;
	else
		cout << "\nsource: ";
	while (!source.empty()) {
		cout << source.top() << " ";
		source.pop();
	}
	cout << endl;

	if (auxiliary.empty())
		cout << "\nauxiliary is empty" << endl;
	else
		cout << "\nauxiliary" << endl;
	while (!auxiliary.empty()) {
		cout << auxiliary.top() << " ";
		auxiliary.pop();
	}
	cout << endl;

	if (destination.empty())
		cout << "destination is empty" << endl;
	else
		cout << "\ndestination: ";
	while (!destination.empty()) {
		cout << destination.top() << " ";
		destination.pop();
	}
	cout << "\n========================================================================" << endl;

}

int main() {

	stack <int> source;
	stack <int> auxiliary;
	stack <int> destination;

	int numDisks = 3;

	for (int i = numDisks; i > 0; --i)
		source.push(i);

	printPins(source, auxiliary, destination);

	destination.push(source.top());
	cout << "\nMove the disk " << source.top() << " from source to destination" << endl;
	source.pop();

	auxiliary.push(source.top());
	cout << "Move the disk " << source.top() << " from source to auxiliary" << endl;
	source.pop();

	auxiliary.push(destination.top());
	cout << "Move the disk " << destination.top() << " from destination to auxiliary" << endl;
	destination.pop();

	destination.push(source.top());
	cout << "Move the disk " << source.top() << " from source to destination" << endl;
	source.pop();

	source.push(auxiliary.top());
	cout << "Move the disk " << auxiliary.top() << " from auxiliary to source" << endl;
	auxiliary.pop();

	destination.push(auxiliary.top());
	cout << "Move the disk " << auxiliary.top() << " from auxiliary to destination" << endl;
	auxiliary.pop();

	destination.push(source.top());
	cout << "Move the disk " << source.top() << " from source to destination" << endl;
	source.pop();

	printPins(source, auxiliary, destination);

	return 0;
}