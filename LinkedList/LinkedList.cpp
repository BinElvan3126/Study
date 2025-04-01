#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct LinkedList 
{
    Node* head;
    Node* tail;
    ~LinkedList() {  // Destructor
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

Node* createNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void creatLinkedList(LinkedList& l)
{
    l.head = nullptr;
    l.tail = nullptr;
}

void insertTail(LinkedList& l, int x)
{
    if (l.head == nullptr) {
        Node* p = createNode(x);
        l.head = p;
        l.tail = p;
    }
    else {
        Node* p = createNode(x);
        l.tail->next = p;
        l.tail = p;
    }
}

void insertHead(LinkedList& l, int x) 
{
    if (l.head == nullptr) {
        Node* p = createNode(x);
        l.head = p;
        l.tail = p;
    }
    else {
        Node* p = createNode(x);
        p->next = l.head;
        l.head = p;
    }
}

void insertYAfterX(LinkedList& l, int x, int y)
{
    Node* cur = l.head;
    while(cur != nullptr) {
        if (cur->data == x) {
            break;
        }
        cur = cur->next;
    }
    if (cur == nullptr) return;
    if (cur == l.tail) insertTail(l, y);
    else {
        Node* p = createNode(y);
        p->next = cur->next;
        cur->next = p;
    }
}

void inputList(LinkedList& l) 
{
    while (true) {
        int x;
        cout << "Ctrl + X -> Enter to escape";
        cin >> x;
        insertTail(l, x);
    }
}

void printLinkedList(LinkedList list) {
    Node* cur = list.head;
    while (cur != NULL) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}

void deleteHead(LinkedList& l)
{
    if (l.head != NULL && l.head == l.tail) {
        Node* p = l.head;
        l.head = l.head -> next;
        delete p;
    }
}

void deleteAll(LinkedList& l) {
    while (l.head != NULL) {
        deleteHead(l);
    }
}

int main() 
{
    LinkedList l;
    creatLinkedList(l);

    deleteAll(l);
    return 0;
}