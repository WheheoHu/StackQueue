
const int ListSize = 100;
const int ListInc = 10;

template<typename T>
class linear_Table {
public:
	linear_Table();
	~linear_Table();
	void InitList();
	void InitList(int ListSize);
	bool ListEmpty();
	void ClearList();
	T GetElem(int location);
	int LocateElem(T element);
	bool ListInsert(int location, T element);//插入元素
	bool ListDelete(int location, T &element);//删除元素
	int ListLenght();//表总长
private:
	T * data;
	int length;
};

template<typename T>
inline linear_Table<T>::linear_Table()
{
	InitList();
	//std::cout << "initialize compelete!" << std::endl;
}

template<typename T>
inline linear_Table<T>::~linear_Table()
{
	delete data;
}

template<typename T>
void linear_Table<T>::InitList() {
	data = new T[ListSize];
	length = 0;
}

template<typename T>
inline void linear_Table<T>::InitList(int ListSize_C)
{
	data = new T[ListSize_C];
	length = 0;
}

template<class T>
bool linear_Table<T>::ListEmpty()
{
	if (length == 0)
	{
		return true;
	}
	return false;
}

template<class T>
void linear_Table<T>::ClearList()
{
	delete[] data;
	length = 0;
}

template<class T>
T linear_Table<T>::GetElem(int location)
{
	if (location<1 || location>length)throw "OUT OF BOUND!";

	return *(data + location - 1);
}

template<class T>
int linear_Table<T>::LocateElem(T element)
{
	for (int i = 0; i < length; i++)
	{
		if (*(data + i) == element)
		{
			return i + 1;
			break;
		}
	}
	return NULL;
}

template<class T>
bool linear_Table<T>::ListInsert(int location, T element)
{

	if (location<1 || location>(length + 1))
	{
		return false;
		throw "OUT OF BOUND!!";
	}
	if (length == ListSize)
	{
		
		T *TempList = new T[ListSize+ListInc];
		memcpy(TempList, data, sizeof(T)*length);
		delete[] data;
		data = TempList;
	}

	for (int i = length; i >= location; i--)
	{
		data[i] = data[i - 1];


	}
	data[location - 1] = element;
	length++;
	return true;


}

template<class T>
bool linear_Table<T>::ListDelete(int location, T & element)
{
	if (location<1 || location>length)
	{
		return false;
		throw "OUT OF BOUND!!";
	}
	element = data[location - 1];
	for (int i = location - 1; i < length - 1; i++)
	{
		data[i] = data[i + 1];
	}
	length--;
	return true;
}

template<class T>
int linear_Table<T>::ListLenght()
{
	return length;
}


