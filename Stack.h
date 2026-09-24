#ifndef STACK_H
#define STACK_H
#include<cstdlib>
template<class T>
class Stack{
    private:
     T *data;
     int capacity;// total size stack ka kitna ha
     int top;//ya batata ha ke last push elemnt kaha ha
    public:
     Stack (int c = 10){
        if(c>0){
            capacity = c;
            top =0;
            data = new T[capacity];
        }
        else
         exit (0);
     }
      //copy constructor
      Stack<T>(const Stack<T> &ref){
        capacity = ref.capacity;
        top = ref.top;
        data = new T[capacity];
        for(int i = 0; i< capacity; i++){
            data[i] = ref.data[i];
        }
        return data;
      } 
      //assingment
      Stack<T>& operator =(const Stack<T> &ref){
        if(this == &ref){
            return *this;
        }
        delete[] data;
        capacity = ref.capacity;
        top = ref.top;
        data = new T[capacity];
        for(int i = 0; i< capacity; i++){
            data[i] = ref.data[i];
        }
        return *this;
      }
      //checking stack is full?
      bool isfull(){
        if(top == capacity )
        return true;
        else
         return false;
      }
      //checking if stack is empty?
      bool isempty(){
        if(top == 0 )
        return true;
        else
         return false;
      } 
      int gettop(){
        return top;
      }
      //data push in stack
      void push(T e){
        if(!isfull()){
            data[top] =e;
            top++;
        }
      }
      //data pop out of stack
    T pop(){
        if(!isempty()){
            top--;
            return data[top];
        }
    }
    T Stacktop(){
        if(!isempty()){
            return data[top-1];
        }
    }
    ~Stack(){
    delete [] data;
}
#endif
};