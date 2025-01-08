#include <iostream>
using namespace std;

const int MaxSize = 100;
int stack1[MaxSize];
int stack2[MaxSize];
int top1 = -1;
int top2 = -1;

bool isEmpty() {
    return (top1 == -1);
}

bool isFull() {
    return (top1 == MaxSize - 1);
}

void Enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }

    while (top1 != -1) {
        top2++;
        stack2[top2] = stack1[top1];
        top1--;
    }

    stack1[top1++] = item;

    while (top2 != -1) {
        top1++;
        stack1[top1] = stack2[top2];
        top2--;
    }
}

int Dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return stack1[top1];
}

