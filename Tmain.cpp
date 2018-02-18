#include <iostream>
template<typename T>
class ArrayList{
    /*
        Class create dynamic array and control it
    */
private:
    int size=0;//size of array
    T *array;//prototype of array
public:
    //default constructor
    ArrayList(){}
    /*
        Constructor with add first value
    */
    ArrayList(T val)

        array = new T[++size];//definition of array
        array[0]= val;//set first value
    }
    /*
        This function create new array and put this->array in it
        then make this->array longer and put new array and value in it
    */
    void addElement(T val){
        //check is array is void
        if(size!=0){
            T *subArray = new T[size];//inalization auxiliary array
            subArray = array;
            array = new T[++size];//set array longer
            array = subArray;
            array[size-1] = val;//set value on last position
            delete [] subArray;
        }else{
            array = new T[++size];//definition of array
            array[0] = val;//set first value
        }
        
    }
    /*
        This function check and return value of this position
        position begin with 1
    */
    T getElement(T pos){
        //check is value of position
        if((pos>=1)&(pos<=size))
            return array[--pos];//return value on this position
        return NULL;
    }
    /*
        This function return size of array
    */
    int getSize(){
        return size;
    }
    /*
        This function is this->array is empty
    */
    bool is_empty() const{
        //run by array while array's value is empty
        //and return false if it have element
        for(int i = 0; i<size;i++){
            if(array[i]!=NULL)
                return false;
        }
        return true;
    }
    /* 
        This function create new array and put this->array in it
        then make this->array longer and put new array and value in it
        value set on a first position
    */
    void pushFront(T val){
            T *subArray = new T[size];//inalization auxiliary array
            subArray = array;
            array = new T[++size];//set array longer
            for(int i =1; i<size;i++)//input value from auxiliary array to this->array
                array[i] = subArray[i-1];//since second position
            array[0] = val;//set first position
            delete [] subArray;
    }
    /* 
        This function create new array and put this->array in it
        then make this->array shorter and put new array without first value in it
    */
    void popFront(){
            T *subArray = new T[--size];//inalization auxiliary array
            for(int i =1; i<=size;i++)//input value from this->array to auxiliary array   
                subArray[i-1]=array[i]; //since second position
            array = new T[size];//set this->array shorter
            array = subArray;//and input auxiliary array to this->array without first volue
            delete [] subArray;
    }
    /*
        This function check is the size more linger then 0
        and return first value or NULL
    */
    T& get_front(){
        if(size!=0)
            return array[0];
        return NULL;
    }
    /*
        This function create new auxiliary array and put this->array to it
        make this->array linger and put auxiliary arra with value on point position to it
    */
    void insert(int pos, T val){
        T *subArray = new T[size];//inalization auxiliary array
        subArray = array;//input auxiliary array to this->array
        *array = new T[++size];// make this->array longer
        array[pos] = val;//set value in point position
        for(int i = 0; i<pos;i++)//set value up to point position
            array[i]=subArray[i];
        for(int i = ++pos;i<size;i++)//set value after point position
            array[i] = subArray[i-1];
        delete [] subArray;
    }

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