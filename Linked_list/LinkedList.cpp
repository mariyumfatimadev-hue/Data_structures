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
	

	
bool search (T key){
	Node<T>*temp = head;
		while(temp !=nullptr){
			if(temp->info ==key){
				return true;
			
			}
		temp = temp->next;	
		}
		return false;
	}
	
void remove(T key){
    if(head == nullptr)
	  return;
	  
    if(head->info == key){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node<T>* previous = head;
    Node<T>* temp = head->next;
    while(temp != nullptr && temp->info != key){
        previous = temp;
        temp = temp->next;
    }
    if(temp == nullptr) return;
    previous->next = temp->next;
    delete temp;
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




int main() {
    Linkedlist<int> list;

    // ---------- Test 1: Empty list pe sab functions (crash nahi hona chahiye) ----------
    cout << "=== Test 1: Empty list ===" << endl;
    list.removeathead();
    list.removeattail();
    list.remove(5);
    list.insertafterkey(1, 5);
    list.insertbeforekey(1, 5);
    list.removeafterkey(5);
    list.removebeforekey(5);
    cout << "search(5): " << list.search(5) << " (expected 0)" << endl;
    cout << "count: " << list.countNodes() << " (expected 0)" << endl;
    list.display();                                  // NULL

    // ---------- Test 2: Insertions ----------
    cout << "\n=== Test 2: Insert at head/tail ===" << endl;
    list.insertattail(10);
    list.insertattail(20);
    list.insertattail(30);
    list.insertathead(5);
    list.display();                                  // 5 -> 10 -> 20 -> 30 -> NULL
    cout << "count: " << list.countNodes() << " (expected 4)" << endl;

    // ---------- Test 3: Search ----------
    cout << "\n=== Test 3: Search ===" << endl;
    cout << "search(20): " << list.search(20) << " (expected 1)" << endl;
    cout << "search(99): " << list.search(99) << " (expected 0)" << endl;

    // ---------- Test 4: insertafterkey ----------
    cout << "\n=== Test 4: insertafterkey ===" << endl;
    list.insertafterkey(25, 20);                     // beech mein
    list.insertafterkey(35, 30);                     // tail ke baad
    list.insertafterkey(100, 99);                    // key nahi, kuch nahi hona
    list.display();                                  // 5 -> 10 -> 20 -> 25 -> 30 -> 35 -> NULL

    // ---------- Test 5: insertbeforekey ----------
    cout << "\n=== Test 5: insertbeforekey ===" << endl;
    list.insertbeforekey(1, 5);                      // head se pehle
    list.insertbeforekey(15, 20);                    // beech mein
    list.insertbeforekey(7, 99);                     // key nahi, kuch nahi hona
    list.display();                                  // 1 -> 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> 35 -> NULL

    // ---------- Test 6: removeafterkey ----------
    cout << "\n=== Test 6: removeafterkey ===" << endl;
    list.removeafterkey(10);                         // 15 delete
    list.removeafterkey(35);                         // tail ke baad kuch nahi
    list.removeafterkey(99);                         // key nahi
    list.display();                                  // 1 -> 5 -> 10 -> 20 -> 25 -> 30 -> 35 -> NULL

    // ---------- Test 7: removebeforekey ----------
    cout << "\n=== Test 7: removebeforekey ===" << endl;
    list.removebeforekey(5);                         // head (1) delete
    list.display();                                  // 5 -> 10 -> 20 -> 25 -> 30 -> 35 -> NULL
    list.removebeforekey(5);                         // key head pe hai, kuch nahi
    list.removebeforekey(20);                        // 10 delete
    list.removebeforekey(99);                        // key nahi
    list.display();                                  // 5 -> 20 -> 25 -> 30 -> 35 -> NULL

    // ---------- Test 8: remove(key) ----------
    cout << "\n=== Test 8: remove(key) ===" << endl;
    list.remove(5);                                  // head
    list.remove(35);                                 // tail
    list.remove(99);                                 // key nahi
    list.remove(25);                                 // beech
    list.display();                                  // 20 -> 30 -> NULL

    // ---------- Test 9: update ----------
    cout << "\n=== Test 9: update ===" << endl;
    cout << "update(20,200): " << list.update(20, 200) << " (expected 1)" << endl;
    cout << "update(99,1): " << list.update(99, 1) << " (expected 0)" << endl;
    list.display();                                  // 200 -> 30 -> NULL

    // ---------- Test 10: Copy constructor (deep copy check) ----------
    cout << "\n=== Test 10: Copy constructor ===" << endl;
    Linkedlist<int> copy(list);
    copy.insertattail(999);
    cout << "original: "; list.display();            // 200 -> 30 -> NULL (999 nahi hona chahiye)
    cout << "copy:     "; copy.display();            // 200 -> 30 -> 999 -> NULL

    // ---------- Test 11: operator= ----------
    cout << "\n=== Test 11: operator= ===" << endl;
    Linkedlist<int> other;
    other.insertattail(1);
    other.insertattail(2);
    other = list;                                    // purani list (1,2) saaf honi chahiye
    other.insertathead(-1);
    cout << "list:  "; list.display();               // 200 -> 30 -> NULL
    cout << "other: "; other.display();              // -1 -> 200 -> 30 -> NULL
    other = other;                                   // self-assignment, crash nahi hona chahiye
    other.display();                                 // -1 -> 200 -> 30 -> NULL

    // ---------- Test 12: Sab kuch remove karke empty ----------
    cout << "\n=== Test 12: Empty karna ===" << endl;
    list.removeattail();
    list.display();                                  // 200 -> NULL
    list.removeattail();                             // single node case
    list.display();                                  // NULL
    list.removeathead();                             // empty pe safe
    cout << "count: " << list.countNodes() << " (expected 0)" << endl;

    // ---------- Test 13: String type (template check) ----------
    cout << "\n=== Test 13: Linkedlist<string> ===" << endl;
    Linkedlist<string> names;
    names.insertattail("Ali");
    names.insertattail("Sara");
    names.insertbeforekey("Mimi", "Sara");
    names.display();                                 // Ali -> Mimi -> Sara -> NULL

    cout << "\nSab tests complete!" << endl;
    return 0;                                        // destructors khud chalenge
}
