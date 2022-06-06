#include<iostream>
template<typename T>
class array
{
private:
    int max_size;
    T** PNew_Array;
    int no_of_elements;

public:
    //constructor for the array
    array();
    //destructor
    ~array();
    // to initiallize the array with ptr
    void init(int start);
    // [REQUIRED] to add an element from the end of the array
    void push_back(const T &item);
    // [REQUIRED] to check if the item accessed is in bounds
    T& operator[] (const int index);
    // [REQUIRED] to remove an item from the array if the condition is true
    void remove_if();
    // [REQUIRED] to check if the condition is true the item will be deleted
    static bool check_condition(int i){return i != 30 ;} ;
    // [OPTIONAL] to increase the max_size of the Array of  dynamically
    void expand();
    // [OPTIONAL] to get the size of an array
    unsigned int getsize() const{ return no_of_elements;}
    

};
template<typename T>
array<T>::array(){
    this->max_size = 10 ;
    this->no_of_elements = 0;
    this->PNew_Array = new T*[this->max_size];
    init(this->no_of_elements);
}
template <typename T>
void array<T>::push_back(const T &item){
    if(this->no_of_elements >= this->max_size)
    {
        this->expand();
    }
    this->PNew_Array[this->no_of_elements++] = new T(item);
}
//Operators
// To check if the index stated is in bounds
template <typename T>
T& array<T>::operator[](const int index){
    if(index<0 || index>=this->no_of_elements){
        throw("This index is out of bounds");
    }
    return *this->PNew_Array[index];
}
template <typename T>
void array<T>::expand(){
    this->max_size *=3;
    T **PtempArr = new T*[this->max_size];
    for(size_t i = 0 ; i <this->no_of_elements;i++){
        PtempArr[i] = new T(*this->PNew_Array[i]);
    }
    for(size_t i = 0 ; i <no_of_elements;i++){
        delete this->PNew_Array[i];
    }
    delete[]this->PNew_Array;
    this->PNew_Array = PtempArr;

    init(this->no_of_elements);
}
template <typename T>
void array<T>::init(int start){
    for(size_t i = start ; i<max_size ; i++){
        this->PNew_Array[i]= nullptr ;
    }
}
template<typename T>
array<T>::~array(){
    for(size_t i = 0 ; i <no_of_elements;i++){
        delete this->PNew_Array[i];
    }
    delete[]this->PNew_Array;
}
template<typename T>
void array<T>::remove_if(){
    for(size_t i = 0 ; i <getsize();i++){
        if(check_condition(**this->PNew_Array))
        {
           **this->PNew_Array=0;
           **this->PNew_Array++;
            no_of_elements--;
        }
        else
        {
            *this->PNew_Array[0]=30;

        }

    }
    for(size_t i =0 ;i<getsize();i++){
        if(**this->PNew_Array==0)
        {
            delete this->PNew_Array[i];
        }
    }

}


int main(){

    
    array<int> myarray;
    //adding elements to the array
    myarray.push_back(10);
    myarray.push_back(20);
    myarray.push_back(30);
    myarray.push_back(40);
    myarray.push_back(50);
    //printing the values of the array
    for(int i =0 ; i<myarray.getsize();i++){
        std::cout<<myarray[i]<<"\n";
    }
    // checking if the operator is working by accessing then checking if it's inside the boundries
    auto item= myarray[2];
    std::cout<<item<<"\n";

    //calling remove if to remove every item except item_3 which is 30
    myarray.remove_if();
    //printing the first value of the container which will be 30 because all of the elements are removed and only 30 left
    std::cout<<myarray[0]<<"\n";



    return 0 ;

}



