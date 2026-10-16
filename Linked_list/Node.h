#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template <class T>
class Node{
    public:
	T info;
    Node<T>* next;
    Node(){
    	next = nullptr;
	}
	Node(T v){
		info = v;
		next = nullptr;
	}
};
#endif