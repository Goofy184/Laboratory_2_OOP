#include <iostream>
#include <algorithm>
#include <vector>
#include "Lab_2.h"
using namespace std;
void fill_with_random_numbers_and_print(const int& n, int  a[])
{
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;
}
int find_position_of_max_element(const int& n, int  a[])
{
    int position_of_max_element = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > a[position_of_max_element]) {
            position_of_max_element = i;
        }
    }
    return position_of_max_element;
}
pair<int, int> find_positions_of_two_zeros(const int& n, int  a[])
{
    int first_zero_position = -1;
    int second_zero_position = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            first_zero_position = i;
        }
        if (a[i] == 0 && first_zero_position !=-1) {
            second_zero_position = i;
            break;
        }
    }
    if (first_zero_position == -1 || second_zero_position == -1) {
        cout << "Not enough null elements found" << endl;
    }
    return pair<int, int>(first_zero_position, second_zero_position);
}

int find_product_between_two_positions(std::pair<int, int>& positions, int  a[10], int n){
    if (positions.first >= n || positions.second >= n) {
        cout << "Positions out of border: " << endl;
        return -1;
    }
    if (positions.first < positions.second) {
        cout << "First position must be before second: " << endl;
        return -1;
    }
    if (positions.first < 0 || positions.second < 0) {
        cout << "Position must be greater than zero: " << endl;
        return -1;
    }
    int product=1;
    for (int i = positions.first + 1; i < positions.second; i++) {
        product *= a[i];
    }
    return product;
}

void sort_for_variant_7(const int& n, int  a[]) {
    vector<int> buffer;
    for (int i = 0, j = 1; i < n && j < n; i++) {
        if (i > 0 && i % 2 != 0) {
            swap(a[i], a[i - j]);
            j++;
        }
        if (i % 2 == 0) {
            buffer.push_back(a[i]);
        }
    }
    for (int i = n / 2, j = 0; i < n; i++, j++) {
        a[i] = buffer[j];
    }
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand(time(NULL));
    const int n = 10;
    int a[n];
    fill_with_random_numbers_and_print(n, a);
    int max_index = find_position_of_max_element(n,a);
    pair<int, int> zeros_positions = find_positions_of_two_zeros(n, a);

    cout << "Max element index: " << max_index << endl;
    cout << "Product of elements between first and second zeros: ";
    cout << find_product_between_two_positions(zeros_positions,a,n)<< endl;
    sort_for_variant_7(n, a);
    cout << "Sorted array: ";
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}