#include <vector>
using namespace std;

//generates Pascal's triangle to n rows
vector<vector<int>> PascalsTriangle(int n) {
    vector<vector<int>> triangle;

    //for when no rows are requested
    if (n <= 0) {
        return triangle; }

    for (int row = 0; row < n; row++) {
        vector<int> currentRow(row + 1);
        currentRow[0] = 1;
        currentRow[row] = 1;

        for (int col = 1; col < row; col++) {
            currentRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col]; }

        triangle.push_back(currentRow); }

    return triangle;
}