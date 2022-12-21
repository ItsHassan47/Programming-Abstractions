#pragma once
#include<iostream>

//template <typename T>
class OurVector
{
	friend std::ostream &operator << (std::ostream &os, const OurVector &v);
private:
	int numItems;
	int *elements;
	int allocatedCapacity;
	void expand();
public:
	OurVector();

	void add(int value);
	void insert(int index, int value);
	void remove(int index);
	int operator[](int index);
	int size() const;
	bool isEmpty() const;
	~OurVector();
};