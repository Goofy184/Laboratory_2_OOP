#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    const int n = 10;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    int max_index = 0;
    int product = 1;
    int first_zero = -1;
    int second_zero = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[max_index]) {
            max_index = i;
        }
        if (a[i] != 0) {
            product *= a[i];
        }
        else {
            if (first_zero == -1) {
                first_zero = i;
            }
            else if (second_zero == -1) {
                second_zero = i;
                break;
            }
        }
    }
    cout << "Max element index: " << max_index << endl;
    cout << "Product of elements between first and second zeros: ";
    if (first_zero == -1 || second_zero == -1) {
        cout << "Знайдено недостатньо нульових елементiв" << endl;
    }
    else {
        for (int i = first_zero + 1; i < second_zero; i++) {
            product *= a[i];
        }
        cout << product << endl;
    }
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            swap(a[i], a[n - i - 1]);
        }

    }

    // виведення перетвореного масиву
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
