#include<iostream>
#include<cmath>
#include<cstdlib>
template<class T>
class Stack{
    private:
     T *data;
     int capacity;// total size stack ka kitna ha
     int size;//abhi kitne elements majood ha
     int top;//ya batata ha ke last push elemnt kaha ha
    public:
     Stack (int c){
        if(c>0){
            capacity = c;
            top =0;
            data = new int[capacity];
        }
        else
         exit (0);
     }
    
};