#include <string>
using namespace std;

// using the naive string matching algorithm.
int findingFirstOccurrence(const string& text, const string& pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    //if a pattern is empty so it will match at 0 
    if (m == 0) {
        return 0; }

    //loop for moving pattern over the text 
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        //comparing at each index 
        while (j < m && text[i + j] == pattern[j]) {
            j++; }

        if (j == m) {
            return i; //full match found 
            }}
    return -1;
}