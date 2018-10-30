#pragma once
#include <iostream>


template<class T>
class Linear_Linked_List
{
public:
	Linear_Linked_List();
	Linear_Linked_List(T elem);
	~Linear_Linked_List();
	void InitList(T firstelem);
	void DestoryList(); 
	bool ListEmpty();
	int ListLength();
	T GetElem(int location);
	int locateElem(T elem);
	int ListInsert(int location, T elem);
	int ListDelete(int location, T& elem);
	int ListDelete(int location);

private:
	struct Node {
		         T data;
		         Node * next;
		         Node(const T &d) :data(d), next(NULL) {}	
	};
	Node * head;
	//寻找第location个Node前一个Node的位置！！！！
	Node * find(const int &location) {
		Node *locaNode = head;
		if (location==1)
		{
			return locaNode;
		}
		for (int i = 0; i < location-2; i++)
		{
			locaNode = locaNode->next;
		}
		return locaNode;
	}
};

template<class T>
inline Linear_Linked_List<T>::Linear_Linked_List()
{
	std::cout << "Please initalize list manually!(Use InitList)" << std::endl;
}

template<class T>
inline Linear_Linked_List<T>::Linear_Linked_List(T elem)
{
	InitList(elem);
}

template<class T>
inline Linear_Linked_List<T>::~Linear_Linked_List()
{
	DestoryList();
}

template<class T>
inline void Linear_Linked_List<T>::InitList(T firstelem)
{
	head = new Node(firstelem);
}

template<class T>
inline void Linear_Linked_List<T>::DestoryList()
{
	Node *p = head;
	
	while (p)
	{
		Node *q = p->next;
		delete p;
		p = q;
	}
}

template<class T>
inline bool Linear_Linked_List<T>::ListEmpty()
{
	return(head == NULL);
}

template<class T>
inline int Linear_Linked_List<T>::ListLength()
{
	int listlenght = 0;
	Node *p = head;
	while (p!=NULL)
	{
		p = p->next;
		listlenght++;
	}
	return listlenght;
}

template<class T>
inline T Linear_Linked_List<T>::GetElem(int location)
{
	/*Node *p = head;
	for (int i = 0; i < (location-1); i++)
	{
		p = p->next;
	}*/
	Node *p = find(location);
	if (location==1)
	{
		return p->data;
	}
	return p->next->data;
}

template<class T>
inline int Linear_Linked_List<T>::locateElem(T elem)
{
	Node *targetNode = head;
	int location = 1;
	while (targetNode->data != elem&&targetNode->next!=NULL)
	{
		targetNode=targetNode->next;
		location++;

	}
	if (targetNode->next==NULL)
	{
		return 0;
	}
	return location;
}

template<class T>
inline int Linear_Linked_List<T>::ListInsert(int location, T elem)
{
	Node *InsertNode =new Node(elem);
	if (location==1)
	{
		InsertNode->next = head;
		
		head = InsertNode;
		return 1;
	}
	if (location>ListLength())
	{
		Node *lastNode = head;
		for (int  i = 0; i < ListLength()-1; i++)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = InsertNode;
		return 1;
	}
	Node *PreNode = head;
	for (int  i = 0; i < location-2; i++)
	{
		PreNode=PreNode->next;
	}
	 InsertNode->next = PreNode->next;
	 PreNode->next = InsertNode;
	 return 1;
}

template<class T>
inline int Linear_Linked_List<T>::ListDelete(int location, T & elem)
{
	Node *deleteNode = head;
	if (location==1)
	{
		elem = deleteNode->data;
		free(head);
		head = deleteNode->next;
		return 1;
	}
	for (int i = 0; i < location-1; i++)
	{
		deleteNode = deleteNode->next;
	}
	Node *tempNode = deleteNode;
	
	elem = deleteNode->next->data;
	free(tempNode);
	deleteNode->next == deleteNode->next->next;
	return 1;
}

template<class T>
inline int Linear_Linked_List<T>::ListDelete(int location)
{
	if (ListLength()==0||location<1||location>ListLength())
	{
		return 0;
	}
	if (location==1)
	{
		head = head->next;
		return 1;
	}
	Node *deleteNode = head;
	for (int i = 0; i < location-2; i++)
	{
		deleteNode = deleteNode->next;
	}
	Node *tempNode = deleteNode->next;
	deleteNode->next = deleteNode->next->next;
	free(tempNode);
	tempNode = NULL;
	return 1;
}

