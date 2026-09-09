#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

//standard matrix multiplication
Matrix Multiply(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j]; }
            result[i][j] = sum;}
    }

    return result;}

// Adding; both hve same size
static Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];}
    }
    return result;}

// Subtracting B from A; both have same size.
static Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];}
    }
    return result;}

// Spliting a n x n matrix into its four n/2 x n/2 quadrants.
static void splitMatrix(const Matrix& M, Matrix& topLeft, Matrix& topRight,
                         Matrix& bottomLeft, Matrix& bottomRight) {
    int half = static_cast<int>(M.size()) / 2;

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            topLeft[i][j] = M[i][j];
            topRight[i][j] = M[i][j + half];
            bottomLeft[i][j] = M[i + half][j];
            bottomRight[i][j] = M[i + half][j + half];} }
}

// Joins four n/2 x n/2 quadrants back into a single n x n matrix.
static Matrix joinMatrix(const Matrix& topLeft, const Matrix& topRight,
                          const Matrix& bottomLeft, const Matrix& bottomRight) {
    int half = static_cast<int>(topLeft.size());
    int n = half * 2;
    Matrix result(n, vector<int>(n, 0));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            result[i][j] = topLeft[i][j];
            result[i][j + half] = topRight[i][j];
            result[i + half][j] = bottomLeft[i][j];
            result[i + half][j + half] = bottomRight[i][j];}
    }

    return result;}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};}

    int half = n / 2;
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    //strassen products.
    Matrix M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenMultiply(addMatrix(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subMatrix(B12, B22));
    Matrix M4 = strassenMultiply(A22, subMatrix(B21, B11));
    Matrix M5 = strassenMultiply(addMatrix(A11, A12), B22);
    Matrix M6 = strassenMultiply(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenMultiply(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combining em all 
    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    return joinMatrix(C11, C12, C21, C22);}