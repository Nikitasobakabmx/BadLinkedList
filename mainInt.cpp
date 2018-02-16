#include <iostream>
class arrayList{
private:
    int size = 1;
    int *array = new int[size];
public:
    arrayList();

    void addElement(int val){
        size++;
        int *subArray = new int[size];
        for(int i = 0;i<size-1;i++)
            subArray[i]=array[i];
        subArray[size-1] = val;
        array = new int[size];
        array = subArray; 
    }

    int size_tget_size() const{
        return size-1;
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
    void erase(){
        for(int i = 0;i < size; i++)
            array[i]=NULL;
    }

    ~arrayList(){
        delete [] array;
    };
};
int main(){
    
    arrayList list;
    for(int i = 0;i<15;i++)
        list.addElement(i);
    // for(int i = 0;i<list.size_tget_size();i++)
    //     std::cout<<list[i]<<std::endl;
    // list.push_front(11);
    // std::cout<<std::endl<<list.get_front()<<std::endl;
    // list.pop_front();
    // std::cout<<list.is_empty()<<std::end;
    // list.erase();
    // std::cout<<list.is_empty();
    return 0;
}