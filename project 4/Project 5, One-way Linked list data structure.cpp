#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
int size = 0;

void InsertAtIndex(int data, int index) {
    if (index < 0 || index > size) {
        cout << "Index should be between 0 and 99" << endl;
        return;
    }
    Node* newNode = new Node{ data, nullptr };
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

void InsertAtEnd(int data) {
    Node* newNode = new Node{ data, nullptr };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void InsertAtBegin(int data) {
    Node* newNode = new Node{ data, nullptr };
    newNode->next = head;
    head = newNode;
    size++;
}

void UpdateNode(int data, int index) {
    if (index < 0 || index >= size) {
        cout << "Index should be between 0 and 99" << endl;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    temp->data = data;
}

int RemoveNodeAtIndex(int index) {
    if (index < 0 || index >= size) {
        cout << "Index should be between 0 and 99" << endl;
        return -1;
    }
    Node* temp = head;
    if (index == 0) {
        head = head->next;
        int data = temp->data;
        delete temp;
        size--;
        return data;
    }
    else {
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        int data = toDelete->data;
        delete toDelete;
        size--;
        return data;
    }
}

int RemoveNodeAtEnd() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return -1;
    }
    if (head->next == nullptr) {
        int data = head->data;
        delete head;
        head = nullptr;
        size--;
        return data;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    int data = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    size--;
    return data;
}

int RemoveNodeAtBegin() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return -1;
    }
    Node* temp = head;
    head = head->next;
    int data = temp->data;
    delete temp;
    size--;
    return data;
}

int SizeOfList() {
    return size;
}

void Concatenate(Node* otherHead) {
    if (head == nullptr) {
        head = otherHead;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = otherHead;
    }
    while (otherHead != nullptr) {
        size++;
        otherHead = otherHead->next;
    }
}

void Invert() {
}