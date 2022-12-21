#include "OurVector.h"

using namespace std;

int main()
{
	OurVector<int> vector;
	vector.add(10);
	vector.add(20);
	vector.add(30);
	cout << vector << endl;

	vector.insert(1, 76);
	cout << vector << endl;

	cout << vector[2] << endl;

	OurVector<string> vector2;
	vector2.add("Hassan");
	vector2.add("Amin");

	cout << vector2 << endl;

	cout << vector2[0] << endl;

	return 0;
}