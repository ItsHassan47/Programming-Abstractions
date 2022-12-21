#include "OurVector.h"

OurVector::OurVector()
{
	numItems = 0;
	allocatedCapacity = 8;
	elements = new int[allocatedCapacity];
}

void OurVector::add(int value)
{
	if (numItems == allocatedCapacity)
		expand();

	elements[numItems] = value;
	numItems++;
}

void OurVector::insert(int index, int value)
{
	if (index < 0 || index >= numItems)
		expand();
	else {
		for (int i = numItems; i > index; --i)
			elements[i] = elements[i - 1];
		elements[index] = value;
		numItems++;
	}
}

int OurVector::operator[] (int index)
{
	if (index < 0 || index >= numItems)
		std::cerr << "Out of bounds!" << std::endl;
	return elements[index];
}

void OurVector::remove(int index)
{
	if (index < 0 || index >= numItems)
		std::cerr << "Out of bounds!" << std::endl;

	else {
		for (int i = index; i < numItems - 1; ++i)
			elements[i] = elements[i + 1];
		numItems--;
	}
}

void OurVector::expand()
{
	allocatedCapacity *= 2;
	int *newElements = new int[allocatedCapacity];

	for (int i = 0; i < numItems; ++i)
		newElements[i] = elements[i];
	
	delete[] elements;

	elements = newElements;
}

int OurVector::size() const
{
	return numItems;
}

bool OurVector::isEmpty() const
{
	return numItems == 0;
}

std::ostream &operator << (std::ostream &os, const OurVector &v)
{
	os << "[ ";
	for (int i = 0; i < v.numItems; ++i)
		os << v.elements[i] << " ";
	os << "]";

	return os;
}

OurVector::~OurVector()
{
	delete[] elements;
}