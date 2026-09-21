#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int val) {
    Node* n = new Node();
    n->data = val;
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node* t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = n;
        n->next = head;
    }
}

void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

void del(int val) {
    if (head == NULL) return;

    Node* curr = head;
    Node* prev = NULL;

    if (head->data == val) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* last = head;
        while (last->next != head) last = last->next;
        last->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    prev = head;
    curr = head->next;
    while (curr != head) {
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    del(20);
    display();
    return 0;
}