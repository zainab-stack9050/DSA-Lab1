#include <iostream>
#include <vector>
using namespace std;

//function declaration
vector<int> findAllIndices(const vector<int>& arr, int key);

// Helper to print the results 
void printResult(const string& testName, const vector<int>& result, const vector<int>& expected) {
    cout << testName << ": ";
    cout << (result == expected ? "pass" : "fail");
    cout << "  Got: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    //multiple occurrences 
    {
        vector<int> arr = {15, 5, 7, 8, 69, 7};
        vector<int> expected = {2, 5};
        vector<int> result = findAllIndices(arr, 7);
        printResult("Test1: multiple occurrences", result, expected); }

    //key is not present 
    {
        vector<int> arr = {1, 2, 3, 4, 5};
        vector<int> expected = {};
        vector<int> result = findAllIndices(arr, 76);
        printResult("Test2: key not present", result, expected);}

    //empty array
    {
        vector<int> arr = {};
        vector<int> expected = {};
        vector<int> result = findAllIndices(arr, 15);
        printResult("Test3: empty array", result, expected);}

    return 0;
}