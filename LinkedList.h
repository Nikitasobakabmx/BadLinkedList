#pragma once
#include <iostream>
#include <stdexcept>
template<typename T>
class LinkedList {
private:
	struct ElementStruct {
		T value;//value
		ElementStruct* next = nullptr;//point to next element
	};
	ElementStruct* mainElement;//start element
	int size = -1;
	static int count = 0;
public:
	/*
	this constructor make list with first value
	*/
	LinkedList(T value);
	/*
	Constructor coping-movement
	*/
	LinkedList(const LinkedList& obj);
	LinkedList();//default constructor
				 /*
				 GetSize return size of all list, starting with 0
				 */
	const int GetSize() const;
	/*
	IsEmpty, check size and return true if size < 0, and false else
	*/
	bool IsEmpty();

	void AddElement(T value);
	/*
	GetElement return value on point position
	*/
	T& GetElement(int pos);
	const T GetElement(int pos) const;
	/*
	With [i], i is int, you can obj[i]=x, x is your value
	*/
	T& operator[](int pos);
	/*
	With [i], i is int, you can obj[i]=x, x is your value
	*/
	const T& operator[](int pos)const;
	/*
	This operator coping-movement work like coping-movement constructor
	*/
	void operator= (const LinkedList& obj);
	/*
	Insert value to first position
	*/
	void PushFront(T value);
	/*
	Erase element on first position
	*/
	void PopFront();
	/*
	With this you can obj.GetFront() = x, x is your value
	*/
	T& GetFront();
	const T& GetFront()const;
	/*
	Insert value to set position
	*/
	void Insert(int pos, T value);
	/*
	Erase element on set position
	*/
	void Erase(int pos);


	~LinkedList();
};
template<typename T>
inline LinkedList<T>::LinkedList(T value)
{
	mainElement = new ElementStruct;// inalizatoin first(main) element of list
	mainElement->value = value;// give him value
	size++;// increment size
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& obj) {
	if (obj.GetElement(0) == nullptr)//check is coping list empty
		return;
	mainElement = new ElementStruct;// inalizatoin first(main) element of list
	mainElement->value = obj.GetElement(0);// coping value
	size = 0;//set default start size
	for (int i = 1; i < obj.GetSize(); i++) {//coping all element
		try {
			AddElement(obj.GetElement(i));
		}
		catch (std::out_of_range) {//catch exception
			std::cout << "Please, chake range" << std::endl;
		}
	}
}

template<typename T>
LinkedList<T>::LinkedList() :mainElement(nullptr) {}//defaul constructor

template<typename T>
const int LinkedList<T>::GetSize() const { return size + 1; }//return size in int

template<typename T>
bool LinkedList<T>::IsEmpty() {//check is empty
	if (size == -1)//if list haven't element him size iz -1
		return true;
	return false;
}
template<typename T>
void LinkedList<T>::AddElement(T value) {
	if (size == -1) {//check is list empty, and give first value
		mainElement = new ElementStruct;//inalization main element
		size++;//increment size
		mainElement->value = value;// set value
		return;
	}
	ElementStruct* temp = mainElement;//create auxiliary varible
	while (temp != nullptr) {//go to last element
		temp = temp->next;
	}
	temp = new ElementStruct;//inalizate last value
	temp->value = value;//set value
	size++;//increment size
}
template<typename T>
T& LinkedList<T>::GetElement(int pos) {
	if (pos > size + 1)//chekc exception
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;//create auxiliary varible
	for (int i = 0; i < pos; i++) {// ran to last value
		if ((pos == (size + 1)) && (i == size)) {//check is we want to add element
			temp->next = new ElementStruct;//inalization auxiliary variable
			temp = temp->next;
			size++;//increment size
			break;
		}//this i throw exception,
		if (temp == nullptr)//check exception
			throw std::invalid_argument("bla");
		temp = temp->next;
	}
	return temp->value;
}
template<typename T>
const T LinkedList<T>::GetElement(int pos) const {
	if (pos > size)//check exception
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;//add auxiliary variable
	for (int i = 0; i < pos; i++) {//run to position
		temp = temp->next;
	}
	return temp->value;
}

template<typename T>
T& LinkedList<T>::operator[](int pos) {
	return GetElement(pos);// go to GetElement
}

template<typename T>//work like move-coping constructor
void LinkedList<T>::operator=(const LinkedList& obj) {//go to therd constructor
	mainElement = new ElementStruct;
	mainElement->value = obj.GetElement(0);
	size = 0;
	for (int i = 0; i < obj.GetSize(); i++) {
		try {
			AddElement(obj.GetElement(i));
		}
		catch (std::out_of_range) {
			std::cout << "Please, chake range" << std::endl;
		}
	}
}

template<typename T>
const T& LinkedList<T>::operator[](int pos) const {
	if (pos > size)//check exception
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;//add auxiliary variable
	for (int i = 0; i < pos; i++) {//go to position
		temp = temp->next;
	}
	return temp->value;
}


template<typename T>
void LinkedList<T>::PushFront(T value) {
	ElementStruct* temp = new ElementStruct;//add auxiliary variable
	temp->value = value;//set value
	temp->next = mainElement;//point to begining
	mainElement = temp;//set new begin
	size++;//increment size
}

template<typename T>
void LinkedList<T>::PopFront() {
	ElementStruct* temp = mainElement;//add auxiliary variable
	mainElement = mainElement->next;//set new begining
	delete temp;// delete old begining
	size--;// decrement size
}

template<typename T>
T& LinkedList<T>::GetFront() {
	return mainElement->value;//return first value
}

template<typename T>
const T & LinkedList<T>::GetFront() const {
	return mainElement->value;//return link to first value
}

template<typename T>
void LinkedList<T>::Insert(int pos, T value) {
	if (pos - 1 > size + 1)//check exception
		throw std::out_of_range("Blaaaa");
	ElementStruct* temp = mainElement;//add auxiliary variable
	for (int i = 0; i < pos - 1; i++) {//go to position before set position
		if ((pos == (size + 1)) && (i == size)) {//add new element
			temp->next = new ElementStruct;
			temp = temp->next;
			temp->value = value;
			size++;
			break;
		}
		temp = temp->next;
	}
	if (pos != size) //insert to set position
		ElementStruct* tempTwo = new ElementStruct;//add second auxiliary variable
		tempTwo->next = temp->next;//point to next element
		temp->next = tempTwo;//point up before element to this element
		tempTwo->value = value;//set value
	}
	size++;//increment size
}

template<typename T>
void LinkedList<T>::Erase(int pos) {
	if (pos == 0)//check is the position first
		PopFront();
	if (pos  > size)//check exception
		throw std::out_of_range("Blaaaa");
	ElementStruct* temp = mainElement;//add auxiliary variable
	for (int i = 0; i < pos - 1; i++) {//go to point position
		temp = temp->next;
	}
	ElementStruct* tempTwo = temp->next;//add auxiliary variab;e
	temp->next = temp->next->next;//delate the while
	delete tempTwo;
	size--;//decrement size
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while (mainElement != nullptr) {//delete element while they won't be
		ElementStruct* temp = mainElement->next;
		delete mainElement;
		mainElement = temp;
	}
}
