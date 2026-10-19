#include "NODE.H"
#include<iostream>
#include<string>
using namespace std;



template <class T>
class Linkedlist{
	
private:
		Node<T>* head;
public:
		Linkedlist(){
			head = nullptr;
		}
	//reverse list	
void reverse_list() {
    Node<T>* prev = nullptr;
    Node<T>* temp = head;
    Node<T>* nextnode = nullptr;

    while (temp != nullptr) {
        nextnode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    head = prev;
}

Linkedlist<T>& operator=(const Linkedlist<T>& other) {
    if (this == &other) 
	 return *this;  
    while (head != nullptr) 
	  removeathead();   
    if (other.head == nullptr) 
	 return *this;
    head = new Node<T>(other.head->info);
    Node<T>* cur = head;
    Node<T>* o = other.head->next;
    while (o != nullptr) {
        cur->next = new Node<T>(o->info);
        cur = cur->next;
        o = o->next;
    }
    return *this;
}




~Linkedlist(){
	
	while(head!=nullptr){
	Node<T> *temp = head ->next;
	delete head;
 head = temp;
}
}
	
};