#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//function declaration
vector<int> findMode(const vector<int>& arr);

void printVector(const vector<int>& v) {
    cout << "{";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "}";}

//comparing vectors without keeping the order in mind
bool sameElements(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;}

void runTest(const string& testName, const vector<int>& input, const vector<int>& expected) {
    cout << "Test: " << testName << endl;
    cout << "  Input:    "; printVector(input); cout << endl;

    vector<int> result = findMode(input);

    cout << "  Output:   "; printVector(result); cout << endl;
    cout << "  Expected: "; printVector(expected); cout << endl;
    cout << "  Result: " << (sameElements(result, expected) ? "PASS" : "FAIL") << endl;
    cout << "----------------------------------------" << endl;}

int main() {
    runTest("Unique mode", {7, 2, 3, 3, 4, 8, 5}, {3});
    runTest("Multiple modes", {3, 9, 2, 9, 3}, {3, 9});
    runTest("Empty array", {}, {});
    runTest("Same element", {15, 15, 15, 15}, {15});
    runTest("All unique elements", {5, 10, 15, 45}, {5, 10, 15, 45});
    return 0;
}