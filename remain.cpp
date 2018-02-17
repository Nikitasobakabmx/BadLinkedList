#include <iostream>
class ArrayList{
private:
    int size=0;
    int *array;
public:
    ArrayList(){}
    ArrayList(int val){
        array = new int[++size];
        array[0]= val;
    }
    void addElement(int val){
        if(size!=0){
            int *subArray = new int[size];
            subArray = array;
            array = new int[++size];
            array = subArray;
            array[size-1] = val;
        }else{
            array = new int[++size];
            array[0] = val;
        }
    }

    int getElement(int pos){
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

    ~ArrayList(){
        delete [] array;
    }

};

int main(){
    ArrayList list(10);
    std::cout<<list.getElement(1)<<std::endl;
    list.addElement(11);
    std::cout<<list.getElement(2);
    std::cout<<list.is_empty()<<std::endl;
    std::cout<<list.getSize();
    return 0;
}