#include <iostream>
using namespace std;

void print(int* arr) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dualPointerSort(int* p, int* q) {
    int* FIN = (p + ((q - p) * 2)) - 1;
    for (; p < FIN; p++) {
        if (p == q) {
            q++;
        }
        int* minor = q;
        for (int* i = q; i <= FIN; i++) {
            if (*minor > *i) {
                minor = i;
            }
        }
        if (*minor < *p) {
            int temp = *p;
            *p = *minor;
            *minor = temp;
        }
    }
}

int main() {
    int arr[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    cout << "Array: ";
    print(arr);
    int* p = arr;
    int* q = arr + 5;
    dualPointerSort(p, q);
    cout << "Sorted array: ";
    print(arr);
}