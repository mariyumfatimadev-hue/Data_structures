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
void remove_duplicates() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        Node<T>* prev = temp;
        Node<T>* current = temp->next;

        while (current != nullptr) {
            if (current->info == temp->info) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        temp = temp->next;
    }
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