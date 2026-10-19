#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* shuffleMerge(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* curr1 = head1;
    Node* curr2 = head2;

    while (curr1 && curr2) {
        Node* next1 = curr1->next;
        Node* next2 = curr2->next;

        curr1->next = curr2;
        if (!next1) break;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }

    return head1;
}