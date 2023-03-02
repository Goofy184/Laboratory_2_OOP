#include <iostream>
#include <algorithm>
#include <vector>
#include "Lab_2.h"
using namespace std;
void fill_with_random_numbers_and_print(const int& n, int  a[10])
{
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand(time(NULL));
    const int n = 10;
    int a[n];
    fill_with_random_numbers_and_print(n, a);
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
        cout << "Not enough null elements found" << endl;
    }
    else {
        for (int i = first_zero + 1; i < second_zero; i++) {
            product *= a[i];
        }
        cout << product << endl;
    }
    cout << "Sorted array: ";
    vector<int> buffer;
    for (int i = 0, j = 1; i < n && j < n; i++) {
        if (i > 0 && i % 2 != 0 ) {
            swap(a[i], a[i-j]);
            j++;
        }
        if (i % 2 == 0) {
            buffer.push_back(a[i]);
        }
    }
    for (int i = n / 2, j=0; i < n; i++, j++) {
        a[i] = buffer[j];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}