#pragma once
#include<iostream>
#include<string>

template <typename T>
class OurVector
{
	template<typename T>
	friend std::ostream &operator << (std::ostream &os, const OurVector<T> &v);
private:
	int numItems;
	T *elements;
	int allocatedCapacity;
	void expand();
public:
	OurVector();
	void add(T value);
	void insert(int index, T value);
	void remove(int index);
	T operator[](int index);
	int size() const;
	bool isEmpty() const;
	~OurVector()
	{
		delete[] elements;
	}
};

template <typename T>
OurVector<T>::OurVector()
{
	numItems = 0;
	allocatedCapacity = 8;
	elements = new T[allocatedCapacity];
}

template <typename T>
void OurVector<T>::add(T value)
{
	if (numItems == allocatedCapacity)
		expand();

	elements[numItems] = value;
	numItems++;
}

template <typename T>
void OurVector<T>::insert(int index, T value)
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

template <typename T>
T OurVector<T>::operator[] (int index)
{
	if (index < 0 || index >= numItems)
		std::cerr << "Out of bounds!" << std::endl;
	return elements[index];
}

template <typename T>
void OurVector<T>::remove(int index)
{
	if (index < 0 || index >= numItems)
		std::cerr << "Out of bounds!" << std::endl;

	else {
		for (int i = index; i < numItems - 1; ++i)
			elements[i] = elements[i + 1];
		numItems--;
	}
}

template <typename T>
void OurVector<T>::expand()
{
	allocatedCapacity *= 2;
	T *newElements = new T[allocatedCapacity];

	for (int i = 0; i < numItems; ++i)
		newElements[i] = elements[i];

	delete[] elements;

	elements = newElements;
}

template <typename T>
int OurVector<T>::size() const
{
	return numItems;
}

template <typename T>
bool OurVector<T>::isEmpty() const
{
	return numItems == 0;
}

template<typename T>
std::ostream &operator << (std::ostream &os, const OurVector <T> &v)
{
	os << "[ ";
	for (int i = 0; i < v.numItems; ++i)
		os << v.elements[i] << " ";
	os << "]";

	return os;
}