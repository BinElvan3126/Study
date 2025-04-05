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

void creatLinkedList(LinkedList& list)
{
    list.head = nullptr;
    list.tail = nullptr;
}

void insertTail(LinkedList& list, int x)
{
    if (list.head == nullptr) {
        Node* p = createNode(x);
        list.head = p;
        list.tail = p;
    }
    else {
        Node* p = createNode(x);
        list.tail->next = p;
        list.tail = p;
    }
}

void insertHead(LinkedList& list, int x) 
{
    if (list.head == nullptr) {
        Node* p = createNode(x);
        list.head = p;
        list.tail = p;
    }
    else {
        Node* p = createNode(x);
        p->next = list.head;
        list.head = p;
    }
}

void insertYAfterX(LinkedList& list, int x, int y)
{
    Node* cur = list.head;
    while(cur != nullptr) {
        if (cur->data == x) {
            break;
        }
        cur = cur->next;
    }
    if (cur == nullptr) return;
    if (cur == list.tail) insertTail(list, y);
    else {
        Node* p = createNode(y);
        p->next = cur->next;
        cur->next = p;
    }
}

void inputList(LinkedList& list) 
{
    while (true) {
        int x;
        cout << "Ctrl + X -> Enter to escape";
        cin >> x;
        insertTail(list, x);
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

void deleteHead(LinkedList& list)
{
    if (list.head != NULL && list.head == list.tail) {
        Node* p = list.head;
        list.head = list.head -> next;
        delete p;
    }
}

void deleteAll(LinkedList& list) {
    while (list.head != NULL) {
        deleteHead(list);
    }
}

int main() 
{
    LinkedList list;
    creatLinkedList(list);

    // deleteAll(list);
    return 0;
}