#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int* values = new int[n];

    //Out of bound access is sorted 
    for (int i = 0; i < n; i++) {
        cin >> values[i]; }

    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";}
    cout << endl;

    //mismatched delete is sorted 
    delete[] values;

    //dangling pointer issue resolved 
    values = nullptr;
    return 0;
}