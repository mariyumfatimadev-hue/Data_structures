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
		
void alternate_merge(Linkedlist<T> &list1, Linkedlist<T> &list2) {
    Node<T>* temp1 = list1.head;
    Node<T>* temp2 = list2.head;
    Node<T>* tail = nullptr; 
    head = nullptr;

    while (temp1 != nullptr && temp2 != nullptr) {
        Node<T>* next1 = temp1->next;
        Node<T>* next2 = temp2->next;

        if (head == nullptr) {
            head = temp1; 
            tail = temp1;
        } else { 
            tail->next = temp1; 
            tail = temp1; 
        }

        tail->next = temp2;
        tail = temp2;

        temp1 = next1; 
        temp2 = next2;
    }

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    list1.head = nullptr;
    list2.head = nullptr;
}
void insertathead(T v){ 
		if(head == nullptr){
			head = new Node<T>(v);
			return;
		}
		
			Node<T>*temp = new Node<T>(v);
			temp->next = head;
			head = temp;
		}
		
		
void insertattail(T v){
		if(head == nullptr){
			head = new Node<T>(v);
			return;
		}
		Node<T>*temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
			
		}
		temp->next = new Node<T>(v);
	}
	
void removeathead(){
		if(head == nullptr){
			return;
		}
     Node<T>*temp = head;
	 head = head->next;
	 delete temp;	
	}
	
	
	
void removeattail(){
		if(head == nullptr){
			return;
		}
		if(head->next == nullptr){
			delete head;
			head = nullptr;
			return;
		}
		
		Node<T>*temp = head;
		while(temp->next->next != nullptr){
		  temp = temp->next;
		  
		}
		delete temp->next;
	    temp->next = nullptr;
	}
	

	

	

		
void insertafterkey(T v, T key){
		Node<T>*temp = head;
		while(temp != nullptr && temp->info != key){
		
			temp = temp->next;
	}
	  if(temp == nullptr)
	    return;
  Node<T>* newnode = new Node<T>(v);
  newnode->next = temp->next;
  temp->next = newnode;
	}


void removeafterkey( T key){
    if (head == nullptr) 
     return;
	Node<T> *temp = head;
 while(temp != nullptr && temp->info != key){
		temp = temp->next;
	}
if(temp == nullptr || temp->next == nullptr){
        return;                        
    }
Node<T> * del = temp->next;
temp->next = del->next;
delete del;

	
}
	
void insertbeforekey(T v, T key){
		if(head == nullptr){
			return;
		}
		if(head ->info ==key){
			Node<T>*newnode = new Node<T>(v);
			newnode->next = head;
			head = newnode;
			return;
		}
		Node<T>*temp = head;
		while(temp != nullptr && temp->next->info != key){
		
			temp = temp->next;
		
	}
	if (temp->next == nullptr) 
	  return;
	Node<T>* newnode = new Node<T>(v);
		newnode->next = temp->next;
		temp->next = newnode;
	}

void removebeforekey(T key) {
        if (head == nullptr || head->next == nullptr) return;
        if (head->info == key) return;       
        if (head->next->info == key) {        
            removeathead();
            return;
        }
        Node<T>* temp = head;                 
        while (temp->next->next != nullptr && temp->next->next->info != key) {
            temp = temp->next;
        }
        if (temp->next->next == nullptr) return;   
        Node<T>* del = temp->next;
        temp->next = del->next;
        delete del;
    }
	



void display(){
    Node<T>* temp = head;
    while(temp != nullptr){
        cout << temp->info << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int countNodes(){
    int count = 0;
    Node<T>* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}


bool update(T oldVal, T newVal){
    Node<T>* temp = head;
    while(temp != nullptr && temp->info != oldVal){
        temp = temp->next;
    }
    if(temp == nullptr){
        return false;                   
    }
    temp->info = newVal;
    return true;
}


Linkedlist(const Linkedlist<T>& other){
    head = nullptr;
    if(other.head == nullptr){
        return;                         
    }
    head = new Node<T>(other.head->info);   
    Node<T>* cur = head;                    
    Node<T>* o = other.head->next;          

    while(o != nullptr){
        cur->next = new Node<T>(o->info);   
        cur = cur->next;
        o = o->next;
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