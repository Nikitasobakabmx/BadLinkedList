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
	mainElement = new ElementStruct;
	mainElement->value = value;
	size++;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& obj) {
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
LinkedList<T>::LinkedList() :mainElement(nullptr) {}

template<typename T>
const int LinkedList<T>::GetSize() const { return size + 1; }

template<typename T>
bool LinkedList<T>::IsEmpty() {
	if (size == -1)
		return true;
	return false;
}
template<typename T>
void LinkedList<T>::AddElement(T value) {
	if (size == -1) {
		mainElement = new ElementStruct;
		size++;
		mainElement->value = value;
		return;
	}
	ElementStruct* temp = mainElement;
	while (temp != nullptr) {
		temp = temp->next;
	}
	temp = new ElementStruct;
	temp->value = value;
	temp->next = nullptr;
	size++;
}
template<typename T>
T& LinkedList<T>::GetElement(int pos) {
	if (pos > size + 1)
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos; i++) {
		if ((pos == (size + 1)) && (i == size)) {
			temp->next = new ElementStruct;
			temp = temp->next;
			size++;
			break;
		}
		if (temp == nullptr)
			throw std::invalid_argument("bla");
		temp = temp->next;
	}
	return temp->value;
}
template<typename T>
const T LinkedList<T>::GetElement(int pos) const {
	if (pos > size)
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	return temp->value;
}

template<typename T>
T& LinkedList<T>::operator[](int pos) {
	return GetElement(pos);
}

template<typename T>
const T& LinkedList<T>::operator[](int pos) const {
	if (pos > size)
		throw std::out_of_range("Your value out of range");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	return temp->value;
}


template<typename T>
void LinkedList<T>::PushFront(T value) {
	ElementStruct* temp = new ElementStruct;
	temp->value = value;
	temp->next = mainElement;
	mainElement = temp;
	size++;
}

template<typename T>
void LinkedList<T>::PopFront() {
	ElementStruct* temp = mainElement;
	mainElement = mainElement->next;
	delete temp;
	size--;
}

template<typename T>
T& LinkedList<T>::GetFront() {
	return mainElement->value;
}

template<typename T>
const T & LinkedList<T>::GetFront() const {
	return mainElement->value;
}

template<typename T>
void LinkedList<T>::Insert(int pos, T value) {
	if (pos - 1 > size + 1)
		throw std::out_of_range("Blaaaa");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos - 1; i++) {
		if ((pos == (size + 1)) && (i == size)) {
			temp->next = new ElementStruct;
			temp = temp->next;
			temp->value = value;
			size++;
			break;
		}
		temp = temp->next;
	}
	if (pos != size) {
		ElementStruct* tempTwo = new ElementStruct;
		tempTwo->next = temp->next;
		temp->next = tempTwo;
		tempTwo->value = value;
	}
	size++;
}

template<typename T>
void LinkedList<T>::Erase(int pos) {
	if (pos == 0)
		PopFront();
	if (pos  > size)
		throw std::out_of_range("Blaaaa");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos - 1; i++) {
		temp = temp->next;
	}
	ElementStruct* tempTwo = temp->next;
	temp->next = temp->next->next;
	delete tempTwo;
	size--;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while (mainElement != nullptr) {
		ElementStruct* temp = mainElement->next;
		delete mainElement;
		mainElement = temp;
	}
}
