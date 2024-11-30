#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int currentSize = 0;

void Insert(int index, int value) {
    if (index >= 0 && index < MAX_SIZE) {
        arr[index] = value;
        if (index >= currentSize) {
            currentSize = index + 1;
        }
    }
    else {
        cout << "index should be below 100" << endl;
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
        cout << "try again!" << endl;
    }
}

void Display() {
    cout << "Array elements: ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Append(int value) {
    if (currentSize < MAX_SIZE) {
        arr[currentSize] = value;
        currentSize++;
    }
    else {
        cout << "Array is full!" << endl;
    }
}

void Reverse() {
    for (int i = 0; i < currentSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[currentSize - i - 1];
        arr[currentSize - i - 1] = temp;
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

int main() {
    int choice, index, value;

    cout << "Enter size of the array ";
    cin >> currentSize;

    cout << "Enter elements: ";
    for (int i = 0; i < currentSize; i++) {
        cin >> arr[i];
    }

    cout << "Insert: Enter index and value: ";
    cin >> index >> value;
    Insert(index, value);

    cout << "Enter value to delete: ";
    cin >> value;
    index = Delete_By_Value(value);
    if (index != -1) {
        cout << "Deleted value at index: " << index << endl;
    }
    else {
        cout << "Value not found!" << endl;
    }

    cout << "Enter index to delete: ";
    cin >> index;
    Delete_By_Index(index);

    Display();

    cout << "Enter value to append: ";
    cin >> value;
    Append(value);

    Reverse();

    cout << "Enter value to search: ";
    cin >> value;
    index = Search_By_Value(value);
    if (index != -1) {
        cout << "Value found at index: " << index << endl;
    }
    else {
        cout << "Value not found!" << endl;
    }
    return 0;
}
