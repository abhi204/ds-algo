/*
 * Singly Linked List Implementation
 */

#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next = NULL;
    Node() {};
    Node(int d) {
        data = d;
    }
};

class LinkedList{
public:
    Node* head = NULL;
    int length = 0;
    LinkedList() {
        head = new Node(-1);                                  // new syntax => pointer-variable = new data-type;
    }
    
    void update(int index, int value) {        
        if (index >= length || index < 0) {
            cout << "Invalid Index" << endl;
            return;
        }
        int counter = -1;                                   // Because we start from head which points to the starting Node of LL
        Node* node = head;
        while(counter != index) {
            node = node->next;
            counter++;
        }
        node->data = value;
    }
    
    void insert(int index, int value) {
        Node* new_node = new Node(value);
        
        if (index >= length || index < 0) {
            cout << "Invalid Index" << endl;
            return;
        }
        int counter = -1;                                   // Because we start from head which points to the starting Node of LL
        Node* old_node = head;
        Node* before_old;
        while(counter != index) {
            before_old = old_node;
            old_node = old_node->next;
            counter++;
        }
        new_node->next = old_node;                    // New node takes place of old_node & old_node moves 1 ahead
        before_old->next = new_node;
        length++;
    }
    
    void append(int value) {
        Node* new_node = new Node(value);
        Node* last_node = head;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
        length++;
    }
    
    void remove(int index) {
        if (index < 0 || index >= length){
            cout <<  "Invalid Index" <<  endl;
            return;
        }
        
        int count = -1;
        Node* prev_node;
        Node* node = head;
        while (count != index) {
            prev_node = node;
            node = node->next;
            count++;
        }
        prev_node->next = node->next;
        delete node;
        length--;
    }
    
};

void display(LinkedList ll){
    Node* node = ll.head->next;
    cout << "LL : " ;
    for(int i=0; i<ll.length ; i++){
        cout << node->data << " ";
        node=node->next;
    }
    cout << "Length=" << ll.length << endl;
}

// Test Implementation
int main() {
    LinkedList ll = LinkedList();
    Node* node;
    cout <<  "initial Length: " << ll.length << endl;
    cout << "Adding 0 1 2 3 4 5" << endl;
    for (int i = 0; i <= 5; i++)
        ll.append(i);
        
    display(ll);
    
    cout <<  "Insert 10 at 3" << endl;
    ll.insert(3, 10);
    display(ll);
    
    cout << "delete 0" <<  endl;
    ll.remove(0);
    display(ll);
    
    cout << "update 0 to 20" <<  endl;
    ll.update(0, 20);
    display(ll);
    
    return 0;
}
