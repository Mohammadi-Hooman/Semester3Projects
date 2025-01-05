#include <iostream>
using namespace std;

const int MaxSize = 100;
int queue[MaxSize];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear == MaxSize - 1);
}

void Enqueue(int object) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = object;
}

int Dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

int Peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue[front];
}

void ReverseQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    int start = front;
    int end = rear;
    while (start < end) {
        int x = queue[start];
        queue[start] = queue[end];
        queue[end] = x;
        start++;
        end--;
    }
}