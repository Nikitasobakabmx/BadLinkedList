#include <iostream>
class ArrayList{
private:
    int size = 0;
    int *array;
public:
    ArrayList(){
        array = new int[1];
    }
    void addElement(int val){
        if(size!=0){
			size++;
			int *subArray = new int[size];
            for(int i = 0; i < size-1; i++)
                subArray[i] = array[i];
            subArray[size-1] = val;
            array = new int[size];
            for(int i = 0;i<size;i++)
                array[i] = subArray[i];
            delete [] subArray;
        }else
            array[0] = val;
    
    }

    int getElement(int pos){
        return array[pos];
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
    list.addElement(10);
    list.addElement(11);
    list.addElement(12);
    for(int i =0; i<list.getSize();i++)
        std::cout<<list.getElement(i)<<std::endl;
    return 0;
}