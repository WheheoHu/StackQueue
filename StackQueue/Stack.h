#pragma once
#include <iostream>

//���ṹ
template<typename T>
struct StackNode
{
	T data;
	
	StackNode(const T &a):data(a) {}

};

template<class T>
class Stack
{
public:
	Stack(int Stacksize);
	~Stack();
	void InitStack();
	void GetTop();
	void Push();
	void Pop();

private:
	StackNode *mainstack;
	StackNode  *top, *bottom;
};

template<class T>
inline Stack<T>::Stack(int Stacksize)
{
	mainstack = new StackNode[Stacksize];
}

template<class T>
inline Stack<T>::~Stack()
{
	delete[] mainstack;
}

template<class T>
inline void Stack<T>::InitStack()
{
}
