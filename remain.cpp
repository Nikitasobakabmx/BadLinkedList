#include <iostream>
class ArrayList{
private:
    int size = 1;
    int *array;
public:
    ArrayList(){
        array = new int[1];
        array[0] = 10;
    }
    void addElement(int val){
        int *subArray = new int[size];
        subArray = array;
        array = new int[++size];
        array = subArray;
        array[size-1] = val;
    }

    int getElement(int pos){
        if(pos!<=0)
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

    ~ArrayList(){
        delete [] array;
    }

};

int main(){
    ArrayList list;
    std::cout<<list.getElement(1)<<std::endl;
    list.addElement(11);
    std::cout<<list.getElement(2);
    return 0;
}