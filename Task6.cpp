#include <iostream>
using namespace std;

int main() {
    int rows, columns;

    cout << "Enter number of students (rows): ";  //reading and checking rows and columns
    cin >> rows;
    cout << "Enter number of subjects (columns): ";
    cin >> columns;

    while (rows <= 0 || columns <= 0) {
        cout << "Invalid. Enter positive values for rows and columns: ";
        cin >> rows >> columns;}

    //allocating a row-pointer array
    int **marks = new int*[rows];
    for (int r = 0; r < rows; r++) {
        marks[r] = new int[columns];}

    //reading marks assuming the numbers are valid 
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << "Marks for student " << r + 1 << ", subject " << c + 1 << ": ";
            cin >> *(*(marks + r) + c);}
    }

    cout << "\nMarks Matrix:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << *(*(marks + r) + c) << "\t"; }
        cout << endl;
    }

    //totals and best student 
    int bestTotal = 0, bestStudent = 1;
    for (int r = 0; r < rows; r++) {
        int total = 0;
        for (int c = 0; c < columns; c++) {
            total += marks[r][c];}
        cout << "Student " << r + 1 << " total: " << total << endl;

        if (r == 0) {
            bestTotal = total;
            bestStudent = 1;
        } else if (total > bestTotal) {   //this condition helps the first tie win 
            bestTotal = total;
            bestStudent = r + 1;}
    }

    cout << "\nHighest total: Student " << bestStudent
         << " with " << bestTotal << " marks.\n";

    //deleting rows then deleting the row-pointer array
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];}
    delete[] marks;
    marks = nullptr;

    return 0;}