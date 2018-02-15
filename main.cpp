#include <iostream>
class arrayList{
private:
arrayList();

template<typename T>
T size_tget_size() const;

bool is_empty() const;

int& operator[](int i);

const int& operator[](int i) const;

void push_front(int val);

void pop_front();

int& get_front();

const int & get_front() const;

template<typename T>
void insert(int pos, T);

void erase(int pos);

~arrayList();
public:

};
int main(){
    
    return 0;
}