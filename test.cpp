#include <iostream>
//#define inc(value1,value2) (value1++;value2++;)
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
ElementStruct* entrance;
ElementStruct* thisElement;//main element, this we cant fogot
int size = 0;//size of all list
int position = 0;
public:
/*
    default constructor
*/
ArrayList(){
    thisElement = entrance = nullptr;
}
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
    if(size == 0){
        thisElement = new ElementStruct;
        entrance = thisElement;
        thisElement->value = value;
    }else{
        ElementStruct* temp = new ElementStruct;
        temp->value = value;
        thisElement->next = temp;
        thisElement = temp;
        delete temp;
        size++;position++;
    }
    // inc(size,position)
}

int GetSize(){
    return size;
}
~ArrayList(){
    thisElement = entrance;
    delete entrance;
    while(thisElement != nullptr){
        ElementStruct* temp = thisElement->next;
        delete thisElement;
        thisElement = temp;
    }
}
};

int main(){
    ArrayList<int> list(12);
    list.AddElement(15);
    //std::cout<<list.GetElement(1);
    list.AddElement(14);
    //std::cout<<list.GetElement(2);
    //std::cout<<list.GetElement(0);
    // for(int i = list.GetSize(); i >= 0; i--)
    //     std::cout<<list.GetElement(i);
    return 0;
}