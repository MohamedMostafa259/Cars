#ifndef TASK2_BACKEND_H
#define TASK2_BACKEND_H

#include <iostream>
#include "StackList.h"
using namespace std;

// (2)


// (3)


// (4)
string convertToNS(int num, int base) {
    if (!(2 <= base && base <= 20))
        return "Error!! The Allowed Range for Base is [2, 20]\n";

    char symbols[20];
    // let's initialize the array
    for (int i = 0; i <= 9; i++) 
        symbols[i] = i + '0';
    for (int i = 10; i <= 19; i++)
        symbols[i] = 'A' + i - 10;

    StackList<char> st;
    string result;
    int res = num / base;
    int rem = num % base;
    while (res != 0) {
        st.push(symbols[rem]);
        rem = res % base;
        res = res / base;
    }
    st.push(symbols[rem]); // push the last element

    while (!st.isEmpty())
        result += st.pop();
    
    return result;
}

// (5)


// (6)


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


    // Test for Function: (6)


    return 0;
}

#endif /* TASK2_BACKEND_H */