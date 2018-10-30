#pragma once
#include <iostream>

//结点结构
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
	T GetTop();
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
	bottom = StackNode<T>(0);
	top = bottom;
	mainstack = top;
}

template<class T>
inline T Stack<T>::GetTop()
{
	return top->data;
}

