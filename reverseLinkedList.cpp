#include <iostream>
using namespace std;

// Definition of a Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a node at the end
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Save next node
        curr->next = prev;   // Reverse link
        prev = curr;         // Move prev
        curr = next;         // Move curr
    }

    return prev;
}

int main() {
    Node* head = NULL;

    // Insert elements
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Original Linked List:" << endl;
    display(head);

    head = reverseList(head);

    cout << "Reversed Linked List:" << endl;
    display(head);

    return 0;
}