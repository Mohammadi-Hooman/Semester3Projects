#include <iostream>
using namespace std;

const int MaxSize = 100;
int stack[MaxSize];
int top = -1;

bool isEmpty() {
	return (top == -1);
}

void Push(int item) {
	if (top == MaxSize - 1) {
		cout << "stack is full";
	}
	else {
		top++;
		stack[top] = item;
	}

int Pop() {
	if (isEmpty()) {
		cout << "stack is empty";
		return -1;
	}
	else {
		return stack[top];
		top--;
	}
}

int Peek() {
	if (isEmpty()) {
		cout << "stack is empty";
	else {
		return stack[top];
	}
	}
}
}
