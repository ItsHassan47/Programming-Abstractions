#include "OurVector.h"

using namespace std;

int main()
{
	OurVector vector;
	vector.add(10);
	vector.add(20);
	vector.add(30);
	cout << vector << endl;

	vector.insert(1, 76);
	cout << vector << endl;
	
	cout << vector[2] << endl;

	return 0;
}