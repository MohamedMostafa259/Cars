#include <iostream>
#include "QueueProject.h"
#include "StackList.h"
#include "task1_backend.h"
#include "task2_backend.h"
using namespace std;
int main() {
    // Test for Function: (2)


    // Test for Function: (3)


    // Test for Function: (4)
    cout << convertToNS(61, 3) << "\n"; // 2021
    cout << convertToNS(0, 3) << "\n"; // 0
    cout << convertToNS(564231, 16) << "\n"; // 89C07
    cout << convertToNS(564231, 10) << "\n"; // 564231
    cout << convertToNS(564231, 8) << "\n"; // 2116007
    cout << convertToNS(564231, 2) << "\n"; // 10001001110000000111
    cout << convertToNS(125, 18) << "\n"; // 6H
    cout << convertToNS(125, 1) << "\n"; // Error!! The Allowed Range for Base is [2, 20]

    // Test for Function: (5)
    cout << "===========" << endl;
    cout << "Enter two large Integers to subtract:\n";
    string num1, num2;
    cin >> num1 >> num2;
    string result = subtractLargeInts(num1, num2);
    cout << "The result is: " << result << endl;
    // Test for Function: (6)


    return 0;
}
