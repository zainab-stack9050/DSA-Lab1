#include <iostream>
#include "utilities.h"
using namespace std;

int main() {
    cout << "add(2,3) == 5: " << (add(2,3) == 5 ? "PASS" : "FAIL") << endl;
    cout << "add(-5, -7) == -10: " << (add(-5, -5) == -10 ? "PASS" : "FAIL") << endl;
    cout << "add(5, 15) == 20: " << (add(-5, -5) == -10 ? "PASS" : "FAIL") << endl;
    return 0;
}
