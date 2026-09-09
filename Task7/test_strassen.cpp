#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<vector<int>> Matrix;

//declarations
Matrix strassenMultiply(const Matrix& A, const Matrix& B);
Matrix Multiply(const Matrix& A, const Matrix& B);

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (size_t j = 0; j < row.size(); j++) {
            cout << row[j];
            if (j + 1 < row.size()) cout << " "; }
        cout << endl;}
}

//generateing an n x n matrix with random integers.
Matrix randomMatrix(int n) {
    Matrix M(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 10; //to have smallr values
        }
    }
    return M;}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    //2x2 multiplication
    {
        Matrix A = {{1, 2}, {3, 4}};
        Matrix B = {{5, 6}, {7, 8}};
        Matrix strassenResult = strassenMultiply(A, B);
        Matrix naiveResult = Multiply(A, B);

        cout << "Test 1 (2x2 multiplication): "
             << (strassenResult == naiveResult ? "pass" : "fail") << endl;
        cout << "Strassen result:" << endl;
        printMatrix(strassenResult);}

    //4x4 multiplication
    {
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        Matrix B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
        Matrix strassenResult = strassenMultiply(A, B);
        Matrix naiveResult = Multiply(A, B);

        cout << "Test 2 (4x4 multiplication): "
             << (strassenResult == naiveResult ? "pass" : "fail") << endl;
        cout << "Strassen result:" << endl;
        printMatrix(strassenResult);}

    //random values compared with naive multiplication (5x5)
    {
        int n = 5;
        Matrix A = randomMatrix(n);
        Matrix B = randomMatrix(n);
        Matrix strassenResult = strassenMultiply(A, B);
        Matrix naiveResult = Multiply(A, B);

        cout << "Test 3 (5x5 random matrices): "
             << (strassenResult == naiveResult ? "pass" : "fail") << endl;}

    return 0;
}