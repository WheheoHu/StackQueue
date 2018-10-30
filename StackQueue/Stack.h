#pragma once
#include <iostream>

//结点结构
template<typename T>
struct StackNode
{
	T data;
	bool isout;
	int time;
	StackNode<T> *nextnode;
	StackNode<T>(const T &d,const int &t) : data(d), nextnode(NULL), isout(false),time(t) {}

};

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	void InitStack();
	T GetTop();
	void Push(T pushdata);
	void Pop();
	void Pop(T& popdata);

private:
	StackNode<T>  *top, *bottom;
};

template<class T>
inline Stack<T>::Stack()
{
	InitStack();
}

template<class T>
inline Stack<T>::~Stack()
{
}

template<class T>
inline void Stack<T>::InitStack()
{
	bottom =new StackNode<T>(0);
	top = bottom;
}

template<class T>
inline T Stack<T>::GetTop()
{
	return top->data;
}

template<class T>
inline void Stack<T>::Push(T pushdata)
{
	StackNode<T> *p = new StackNode<T>(pushdata);
	p->nextnode = top; 
	top = p;
}

template<class T>
inline void Stack<T>::Pop()
{
	StackNode<T> *temp = top->nextnode;
	top = temp;
}

template<class T>
inline void Stack<T>::Pop(T& popdata)
{
	StackNode<T> *temp = top->nextnode;
	popdata = temp->data;
	top = temp;
	free(temp);
	temp = NULL;
	
}

