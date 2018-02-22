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

public:
int size = -1;//size of all list
int position = -1;
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
    while(position != size){
        ElementStruct* temp = thisElement->next;
        thisElement = temp;
    }
    if(size == -1){
        thisElement = new ElementStruct;
        thisElement->value = value;
        entrance = thisElement;
        
    }else{
        ElementStruct* temp = new ElementStruct;
        temp->value = value;
        thisElement->next = temp;
        thisElement = temp;       
    }
    size++;position++;
}
T GetElement(int pos){
    if(pos > size)
        return NULL;
    if (pos == position)
        return thisElement->value;
    if(pos < position){
        position = 0;
        thisElement = entrance;
        
    }
    while(position<pos){
        ElementStruct* temp = thisElement->next;
        thisElement = temp;
        position++;
        
    }
    return thisElement->value;
}

int GetSize(){
    return size;
}
~ArrayList(){
    thisElement = entrance;
    while(thisElement != nullptr){
        ElementStruct* temp = thisElement->next;
        delete thisElement;
        thisElement = temp;
    }
}
};

int main(){
    ArrayList<int> list(11);    
    list.AddElement(15);
    list.AddElement(14);
    for(int i = list.GetSize(); i >= 0; i--)
        std::cout<<list.GetElement(i)<<std::endl;
    return 0;
}