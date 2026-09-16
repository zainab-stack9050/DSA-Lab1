#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (1-10): ";
    cin >> n;
    while (n < 1 || n > 10) {
        cout << "Invalid!!!!. Enter n between 1 and 10: ";
        cin >> n;}

    int *marks = new int[n];
    cout << "Enter " << n << " marks:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);}

    int newMark;
    cout << "Enter new mark: ";
    cin >> newMark;
    //allocating a second block, copying old mark and appending new mark
    int *newMarks = new int[n + 1];
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);}
    *(newMarks + n) = newMark;

    //releasing old block and repointing marks with updating size
    delete[] marks;
    marks = newMarks;
    n = n + 1;

    cout << "Updated marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " "; }
    cout << endl;

    delete[] marks; //releasing the final block 
    marks = nullptr;
    return 0;}