#include <iostream>
#include <vector>
using namespace std;

//function declaration 
vector<vector<int>> PascalsTriangle(int n);

//helper function to print 
void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i + 1 < row.size()) cout << " ";}
        cout << endl;}
}
bool rowEquals(const vector<int>& row, const vector<int>& expected) {
    return row == expected;}

int main() {
    //for n = 0 
    {
        auto triangle = PascalsTriangle(0);
        cout << "Test 1 (n = 0): " << (triangle.empty() ? "Pass" : "Fail")
             << "  Rows returned: " << triangle.size() << endl; }

    //for n = 1 
    {
        auto triangle = PascalsTriangle(1);
        bool pass = triangle.size() == 1 && rowEquals(triangle[0], {1});
        cout << "Test 2 (n = 1): " << (pass ? "Pass" : "Fail") << endl;}

    //for n = 5 
    {
        auto triangle = PascalsTriangle(5);
        bool pass = triangle.size() == 5 && rowEquals(triangle[4], {1, 4, 6, 4, 1});
        cout << "Test 3 (n = 5, row 5 check): " << (pass ? "Pass" : "Fail") << endl;
        cout << "Full triangle for n = 5:" << endl;
        printTriangle(triangle);}

    return 0;
}