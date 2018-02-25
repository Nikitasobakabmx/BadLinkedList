#pragma once
#include "stdafx.h"
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
	LinkedList();//default constructor
				 /*
				 GetSize return size of all list, starting with 0
				 */
	int GetSize();
	/*
	IsEmpty, check size and return true if size < 0, and false else
	*/
	bool IsEmpty();
	/*
	GetElement return value on point position
	*/
	T& GetElement(int pos);
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
LinkedList<T>::LinkedList() :mainElement(nullptr) {}

template<typename T>
int LinkedList<T>::GetSize() { return size + 1; }

template<typename T>
bool LinkedList<T>::IsEmpty() {
	if (size == -1)
		return true;
	return false;
}

template<typename T>
T& LinkedList<T>::GetElement(int pos) {
	if (pos > size + 1)
		throw std::out_of_range("Blaaaa");
	ElementStruct* temp = mainElement;
	for (int i = 0; i < pos; i++) {
		if ((pos == (size + 1)) && (i == size)) {
			temp->next = new ElementStruct;
			temp = temp->next;
			size++;
			break;
		}
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
	return GetElement(pos);
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
void LinkedList<T>::Erase(int pos){
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
