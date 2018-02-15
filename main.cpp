#include <iostream>
class arrayList{
private:
    int size = 1;
    template<typename T>
    T *array = new T[size];
public:
    arrayList();

    template<typename T>
    T size_tget_size() const{
        return size;
    };

    bool is_empty() const{
        for(int i = 0;i < size;i++)
            if(array[i]!=NULL)
                return false;
        return true;
    };

    int& operator[](int i){
        return array[i];
    };

    const int& operator[](int i) const{
        return array[i];
    };

    template<typename T>
    void push_front(int val){
        T *subArray = new T[size];
        subArray = array;
        size++;
        *array = new T[size];
        array = subArray;
        delete [] subArray;
    };

    void pop_front(){
        T *subArray = new T[size];
        subArray = array;
        size--;
        *array = new T[size];
        for(int i = 0; i<size;i++)
            array[i]=subArray[i+1];
        delete [] subArray;
    }

    template<typename T>
    T& get_front(){
        return array[0];
    };

    const int & get_front() const{
        return array[0];
    };

    template<typename T>
    void insert(int pos, T val){
        T *subArray = new T[size];
        subArray = array;
        size++;
        *array = new T[size];
        array[pos] = val;
        for(int i = 0; i<pos;i++)
            array[i]=subArray[i];
        for(int i = ++pos;i<size;i++)
            array[i] = subArray[i-1];
        delete [] subArray;
    };
    template<typename T>
    void erase(int pos){
        T *subArray = new T[size];
        subArray = array;
        size--;
        *array = new T[size];
        for(int i = 0; i<pos;i++)
            array[i]=subArray[i];
        for(int i = ++pos;i<size;i++)
            array[i] = subArray[i+1];
        delete [] subArray;
    };

    ~arrayList(){
        delete [] array;
    };
};
int main(){
    
    return 0;
}