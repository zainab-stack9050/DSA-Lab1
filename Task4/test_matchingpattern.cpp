#include <iostream>
#include <string>
using namespace std;

//function declaration 
int findingFirstOccurrence(const string& text, const string& pattern);
//basic way to print results (helper function)
void printResult(const string& testName, int result, int expected) {
    cout << testName << ": " << (result == expected ? "Pass" : "Fail")
         << "  Got: " << result << " (expected " << expected << ")" << endl;}

int main() {
    //pattern at the beginning 
    printResult("Test 1 (pattern at beginning)",
                findingFirstOccurrence("Zainab Parveen", "Zainab"), 0);

    //pattern at the end 
    printResult("Test 2 (pattern at end)",
                findingFirstOccurrence("BS AI", "AI"), 3);

    //pattern is not present 
    printResult("Test 3 (pattern not present)",
                findingFirstOccurrence("SEECS NUST", "NBS"), -1);

    //empty pattern
    printResult("Test 4 (empty pattern)",
                findingFirstOccurrence("DSA Lab", ""), 0);

    return 0;
}