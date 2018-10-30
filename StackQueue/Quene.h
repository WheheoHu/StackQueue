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
	void entreQuene();
	void outQuene();

private:
	QueneNode<T> *head, rear;
};

template<class T>
inline void Quene<T>::InitQuene()
{
	rear = new QueneNode<T>(0);
	head = rear;

}
