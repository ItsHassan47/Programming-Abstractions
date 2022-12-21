#pragma once
#include<iostream>

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack(); // constructor
    ~Stack();

    void push(int value);
    int first() const;
    int pop();
    bool isEmpty() const;
};