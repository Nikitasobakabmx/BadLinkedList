#include <iostream>
template<typename T>
class ArrayList{
private:
/*
    Struct who have point to next element / or to main element
    And value of element
*/
struct ElementStruct{
    T value;
    ElementStruct* next = nullptr;
};
ElementStruct* thisElement;//dinamic element, have actual element
ElementStruct* headElement;//main element, this we cant fogot
int size = 0;//size of all list
int position = 0;
public:
/*
    default constructor
*/
ArrayList(){}
/*  
    constructor who create first element
    also ctreate identical actual element
*/
ArrayList(T value){
    AddElement(value);
}
/*
    create auxiliary element, give him pointers and put to actualy element
*/
void AddElement(T value){
    if(size!=0){
        ElementStruct* temp = new ElementStruct;
        temp->value = value;
        thisElement->next = temp;
        thisElement = temp;
        delete temp;
    }else{
        headElement = new ElementStruct;//inalization of main element
        headElement->value = value;//give value
        thisElement = headElement;//copy to actualy element
        headElement->next = thisElement;
    }
    size++;
    position++;
}
/*
    This function return element on pount position
    if poin position isn't in list return nullptr
*/
T GetElement(int position){
    if(position > size)
        return NULL;
    if(position == this->position)
        return thisElement->value;
    else{
        ElementStruct* temp; 
        if(position < this->position){
            this->position = 0;
            thisElement = headElement;
        }
        do{
            temp = thisElement->next;
            delete thisElement;
            thisElement = temp;
            this->position++;
        }while(this->position!=position);
        delete temp;
        return thisElement->value;
    }
}
int GetSize(){
    return size;
}
~ArrayList(){
    ElementStruct* temp;
    while(headElement!=nullptr){
        temp = headElement->next;
        delete headElement;
        headElement = temp;
    }
    delete temp;
    delete thisElement;
}
};

int main(){
    ArrayList<int> list(12);
    list.AddElement(15);
    list.AddElement(14);
    for(int i = list.GetSize(); i >= 0; i--)
        std::cout<<list.GetElement(i);
    return 0;
}