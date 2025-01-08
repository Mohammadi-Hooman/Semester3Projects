#include <iostream>
using namespace std;

const int MaxSize = 100;
int queue[MaxSize];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % MaxSize == front);
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
        rear = (rear + 1) % MaxSize;
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
        front = (front + 1) % MaxSize;
    }
    return queue[front];
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
    while (start != end && (start + 1) % MaxSize != end) {
        int x = queue[start];
        queue[start] = queue[end];
        queue[end] = x;
        start = (start + 1) % MaxSize;
        end = (end - 1 + MaxSize) % MaxSize;
    }
}
