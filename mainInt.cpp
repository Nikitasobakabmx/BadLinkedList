#include <iostream>
class arrayList{
private:
    int size = 1;
    int *array = new int[size];
public:
    arrayList();

    int size_tget_size() const{
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

    void push_front(int val){
        int *subArray = new int[size];
        subArray = array;
        size++;
        array = new int[size];
        array = subArray;
        delete [] subArray;
    };

    void pop_front(){
        int *subArray = new int[size];
        subArray = array;
        size--;
        array = new int[size];
        for(int i = 0; i<size;i++)
            array[i]=subArray[i+1];
        delete [] subArray;
    }

    int& get_front(){
        return array[0];
    };

    const int & get_front() const{
        return array[0];
    };

    void insert(int pos, int val){
        int *subArray = new int[size];
        subArray = array;
        size++;
        array = new int[size];
        array[pos] = val;
        for(int i = 0; i<pos;i++)
            array[i]=subArray[i];
        for(int i = ++pos;i<size;i++)
            array[i] = subArray[i-1];
        delete [] subArray;
    };
    void erase(int pos){
        int *subArray = new int[size];
        subArray = array;
        size--;
        array = new int[size];
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