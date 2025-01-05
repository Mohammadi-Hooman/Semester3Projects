#include <iostream>
using namespace std;

const int MaxSize = 100;
int arr[MaxSize];
int currentSize = 0;

void Insert(int index, int value) {
    if (index <= 99 && index >= 0) {
        for (int i = 98; i = index + 1; i--)
        {
            arr[index + 1] = arr[index];
        }
        if (index >= currentSize) {
            currentSize = index + 1;
        }
    }
    else {
        cout << "index should be below between 0 and 99" << endl;
    }
}

int Delete_By_Value(int value) {
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == value) {
            for (int j = i; j < currentSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            currentSize--;
            return i;
        }
    }
    return -1;
}

void Delete_By_Index(int input) {
    if (input >= 0 && input < currentSize) {
        for (int j = input; j < currentSize - 1; j++) {
            arr[j] = arr[j + 1];
        }
        currentSize--;
    }
    else {
        cout << "input should be between 0 and currentSize" << endl;
    }
}

void Display() {
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Append(int value) {
    if (currentSize < MaxSize) {
        arr[currentSize] = value;
        currentSize++;
    }
    else {
        cout << "array is full" << endl;
    }
}

void Reverse() {
    for (int i = 0; i < currentSize / 2; i++) {
        int x = arr[i];
        arr[i] = arr[currentSize - i - 1];
        arr[currentSize - 1 - i] = x;
    }
}

int Search_By_Value(int value) {
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}