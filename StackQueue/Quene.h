#pragma once

template<typename T>
struct QueneNode
{
	T data;
	QueneNode<T> *nextnode;
	QueneNode<T>(const T &d) : data(d), nextnode(NULL) {}
};

template<class T>
class Quene
{
public:
	Quene();
	~Quene();
	void InitQuene();
	void entreQuene(T data);
	QueneNode<T>* outQuene();

private:
	QueneNode<T> *head, *rear;
};

template<class T>
inline Quene<T>::Quene()
{
	InitQuene();
}

template<class T>
inline Quene<T>::~Quene()
{
}

template<class T>
inline void Quene<T>::InitQuene()
{
	rear = new QueneNode<T>(0);
	head = rear;
}

template<class T>
inline void Quene<T>::entreQuene(T data)
{
	QueneNode<T> *p = new QueneNode<T>(data);
	p->nextnode = head;
	head = p;
}

template<class T>
inline QueneNode<T>* Quene<T>::outQuene()
{
	QueneNode<T> *p = head;
	
	if (p->nextnode==rear)
	{
		QueneNode<T> *temp = p;
		head = rear;
		return temp;
		free(temp);
	}
	else
	{
		while (p->nextnode->nextnode != rear)
		{
			p = p->nextnode;
		}
		QueneNode<T> *temp = p->nextnode;
		p->nextnode = p->nextnode->nextnode;
		return temp;
		free(temp);
	}
	
	
}

