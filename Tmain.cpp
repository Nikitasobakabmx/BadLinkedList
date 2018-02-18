#include "stdafx.h"
#include <iostream>
template<typename T>
class ArrayList {
	/*
	Class create dynamic array and control it
	*/
private:
	int size = 0;//size of array
	T *array;//prototype of array
public:
	//default constructor
	ArrayList() {}
	/*
	Constructor with add first value
	*/
	ArrayList(T val) {
		array = new T[++size];//definition of array
		array[0] = val;//set first value
	}
	/*
	This function create new array and put this->array in it
	then make this->array longer and put new array and value in it
	*/
	void addElement(T val) {
		//check is array is void
		if (size != 0) {
			T *subArray = new T[size];
			subArray = array;
			array = new T[++size];
			for (int i = 0; i < size - 1; i++)
				array[i] = subArray[i];
			array[size - 1] = val;
			//array = new T[++size];//set array longer
			//array = subArray;
			//array[size-1] = val;//set value on last position
			delete[] subArray;
		}
		else {
			array = new T[++size];//definition of array
			array[0] = val;//set first value
		}

	}
	/*
	This function check and return value of this position
	position begin with 0
	*/
	T getElement(T pos) {
		//check is value of position
		if ((pos >= 0)&(pos <= size))
			return array[pos];//return value on this position
		return NULL;
	}
	/*
	This function return size of array
	*/
	int getSize() const {
		return size;
	}
	/*
	This function is this->array is empty
	*/
	bool is_empty() const {
		//run by array while array's value is empty
		//and return false if it have element
		for (int i = 0; i<size; i++) {
			if (array[i] != NULL)
				return false;
		}
		return true;
	}
	/*
	This function create new array and put this->array in it
	then make this->array longer and put new array and value in it
	value set on a first position
	*/
	void pushFront(T val) {
		T *subArray = new T[size];//inalization auxiliary array
		subArray = array;
		array = new T[++size];//set array longer
		for (int i = 1; i<size; i++)//input value from auxiliary array to this->array
			array[i] = subArray[i - 1];//since second position
		array[0] = val;//set first position
		delete[] subArray;
	}
	/*
	This function create new array and put this->array in it
	then make this->array shorter and put new array without first value in it
	*/
	void popFront() {
		T *subArray = new T[--size];//inalization auxiliary array
		for (int i = 1; i <= size; i++)//input value from this->array to auxiliary array   
			subArray[i - 1] = array[i]; //since second position
		array = new T[size];//set this->array shorter
		array = subArray;//and input auxiliary array to this->array without first volue
		delete[] subArray;
	}
	/*
	This is two function check is the size more linger then 0
	and return first value or NULL
	one if this is const
	*/
	T get_front() {
		if (size != 0)
			return array[0];
		return NULL;
	}
	const T get_front() const {
		if (size != 0)
			return array[0];
		return NULL;
	}
	/*
	This two function of operators
	who return value on gizen position
	one of this is const
	position begin with 0
	*/
	int operator[](int pos) {
		return array[pos];
	}
	const int operator[](int pos) const {
		return array[pos];
	}
	/*
	This function create new auxiliary array and put this->array to it
	make this->array linger and put auxiliary arra with value on point position to it
	*/
	void insert(int pos, T val) {
		T *subArray = new T[size];//inalization auxiliary array
		subArray = array;//input this->array to auxiliary
		array = new T[++size];// make this->array longer
		array[pos] = val;//set value in point position
		for (int i = 0; i<pos; i++)//set value up to point position
			array[i] = subArray[i];
		for (int i = ++pos; i<size; i++)//set value after point position
			array[i] = subArray[i - 1];
		delete[] subArray;
	}
	/*
	This function erase value on point position in this->array
	*/
	void erase(int pos) {
		T *subArray = new T[size];//inalization auxiliary array
		subArray = array;//input this->array to auxiliary array
		array = new T[--size];//make this->array sorter
		for (int i = 0; i<pos; i++)//set value up to point position
			array[i] = subArray[i];
		for (int i = ++pos; i<size; i++)//set value after point position
			array[i] = subArray[i + 1];
		delete[] subArray;
	}

	~ArrayList() {
		delete[] array;
	}

};

int main() {
	int i = 19;
	ArrayList<int> list(i);
	std::cout << list.get_front() << std::endl;
	list.popFront();
	list.addElement(i);
	list.addElement(++i);
	list.addElement(++i);
	list.addElement(++i);
	for (int i = 1; i<10; i++)
		list.addElement(i);
	list.pushFront(4);
	std::cout << list.get_front() << std::endl;
	for (int i = 1; i < list.getSize(); i++)
		std::cout << list.getElement(i) << "\t";
	system("pause");

	return 0;
}