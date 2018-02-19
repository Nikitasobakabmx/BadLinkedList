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
    ElementStruct* next;
};
ElementStruct* thisElement;//dinamic element, have actual element
ElementStruct* headElement;//main element, this we cant fogot
int size = 0;//size of all list
public:
/*  
    constructor who create first element
    also ctreate identical actual element
    elements create cycle
*/
ArrayList(T value){
    headElement = new ElementStruct;//inalization of main element
    headElement->value = value;//give value
    thisElement = headElement;//copy to actualy element
    headElement->next = thisElement;//create cycle
    thisElement->next =  headElement;//create cycle;
    size++;
}
/*
    create auxiliary element, give him pointers and put to actualy element
*/
void AddElement(T value){
    ElementStruct* temp = new ElementStruct;
    temp->value = value;
    temp->next =  headElement;
    thisElement->next = temp;
    thisElement = temp;  
    size++;
    delete temp;
}
T GetElement(){
    return thisElement->value;
}
~ArrayList(){
    delete thisElement;
    delete headElement;
}
};

int main(){
    ArrayList<int> list(12);
    std::cout<<list.GetElement();
    return 0;
}