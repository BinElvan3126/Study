#include <iostream>

using namespace std;

typedef struct singlyNode
{
    int data;
    singlyNode *next;
} NODE;

typedef struct singlyList 
{
    singlyNode *head;
    singlyNode *tail;
    ~singlyList() {  // Destructor
        singlyNode *current = head;
        while (current != nullptr) {
            singlyNode *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
} LIST;

singlyNode *createSinglyNode(int x)
{
    singlyNode *p = new singlyNode;
    p->data = x;
    p->next = nullptr;
    return p;
}

void creatSinglyLinkedList(singlyList& list)
{
    list.head = nullptr;
    list.tail = nullptr;
}

void insertTailSinglyList(singlyList& list, int x)
{
    if (list.head == nullptr) {
        singlyNode *p = createSinglyNode(x);
        list.head = p;
        list.tail = p;
    }
    else {
        singlyNode *p = createSinglyNode(x);
        list.tail->next = p;
        list.tail = p;
    }
}

void insertHeadSinglyList(singlyList& list, int x) 
{
    if (list.head == nullptr) {
        singlyNode *p = createSinglyNode(x);
        list.head = p;
        list.tail = p;
    }
    else {
        singlyNode *p = createSinglyNode(x);
        p->next = list.head;
        list.head = p;
    }
}

void insertYAfterXSinglyList(singlyList& list, int x, int y)
{
    singlyNode *cur = list.head;
    while(cur != nullptr) {
        if (cur->data == x) {
            break;
        }
        cur = cur->next;
    }
    if (cur == nullptr) return;
    if (cur == list.tail) insertTailSinglyList(list, y);
    else {
        singlyNode* p = createSinglyNode(y);
        p->next = cur->next;
        cur->next = p;
    }
}

void inputSinglyList(singlyList& list) 
{
    while (true) {
        int x;
        cout << "Ctrl + X -> Enter to escape";
        cin >> x;
        insertTailSinglyList(list, x);
    }
}

void printSinglyLinkedList(singlyList list) {
    singlyNode *cur = list.head;
    while (cur != NULL) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}

void deleteHead(singlyList& list)
{
    if (list.head != NULL && list.head == list.tail) {
        singlyNode* p = list.head;
        list.head = list.head -> next;
        delete p;
    }
}

void deleteAll(singlyList& list) {
    while (list.head != NULL) {
        deleteHead(list);
    }
}

// Doubly Linkedlist

typedef struct doublyNode 
{
    int data;
    doublyNode *next, *prev;
} D_NODE;

typedef struct doublyList
{
    doublyNode *head;
    doublyNode *tail;
} D_LIST;

// Circular Single Linkedlist

typedef struct circularNode
{
    int data;
    circularNode *next;
} C_NODE;

typedef struct circularList
{
    circularNode *head;
    circularNode *tail;
} C_LIST;

// Circular Doubly Linkedlist

typedef struct circularDoublyNode {
    int data;
    circularDoublyNode *next, *prev;
} CD_NODE;

typedef struct circularDoublyList {
    circularDoublyNode *head;
    circularDoublyNode *tail;
} CD_LIST;

int main() 
{
    singlyList list;
    creatSinglyLinkedList(list);

    // deleteAll(list);
    return 0;
}