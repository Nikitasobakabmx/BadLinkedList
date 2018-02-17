#include <iostream>
template<typename T>
class ArrayList{
private:
    int size=0;
    T *array;
public:
    ArrayList(){}
    ArrayList(T val){
        array = new T[++size];
        array[0]= val;
    }
    void addElement(T val){
        if(size!=0){
            T *subArray = new T[size];
            subArray = array;
            array = new T[++size];
            array = subArray;
            array[size-1] = val;
        }else{
            array = new T[++size];
            array[0] = val;
        }
    }

    T getElement(T pos){
        if(pos>=0)
            return array[--pos];
        return NULL;
    }

    int getSize(){
        return size;
    }

    bool is_empty() const{
        for(int i = 0; i<size;i++){
            if(array[i]!=NULL)
                return false;
        }
        return true;
    }

    void pushFront(T val){
            T *subArray = new T[size];
            subArray = array;
            array = new T[++size];
            for(int i =1; i<size;i++)
                array[i] = subArray[i-1];
            array[0] = val;
    }

    void popFront(){
            T *subArray = new T[--size];
            for(int i =1; i<=size;i++)
                subArray[i-1]=array[i];
            array = new T[size];
            array = subArray;
    }
    
    T& get_front(){
        return array[0];
    };
    ~ArrayList(){
        delete [] array;
    }
    
};

int main(){
    ArrayList<int> list(10);
    std::cout<<list.getElement(1)<<std::endl;
    list.addElement(11);
    std::cout<<list.getElement(2)<<std::endl;
    std::cout<<list.is_empty()<<std::endl;
    std::cout<<list.getSize()<<std::endl;
    list.pushFront(3);
    std::cout<<list.getElement(1)<<std::endl;
    std::cout<<list.getElement(2)<<std::endl;
    std::cout<<list.getElement(3)<<std::endl;
    list.popFront();
    std::cout<<list.getElement(1)<<std::endl;
    std::cout<<list.getElement(2)<<std::endl;
    std::cout<<list.get_front();
    return 0;
}