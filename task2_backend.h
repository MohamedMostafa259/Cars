#ifndef TASK2_BACKEND_H
#define TASK2_BACKEND_H

#include <iostream>
#include "StackList.h"
using namespace std;

template <typename T>
void copyStack(StackList<T>& s1, StackList<T>& s2) {
    StackList<T> tempStack;


    while (!s1.isEmpty()) {
        tempStack.push(s1.top());
        s1.pop();
    }

    while (!tempStack.isEmpty()) {
        s2.push(tempStack.top());
        tempStack.pop();
    }
}



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
string subtractLargeInts (const string &num1, const string &num2) {
    StackList<unsigned char> greaterInt, smallerInt, finalAns;
    string greaterNum;
    string smallerNum;
    size_t length1 = num1.length();
    size_t length2 = num2.length();
    size_t differenceOfDigits = 0;
    if (length1 > length2){
        greaterNum = num1;
        smallerNum = num2;
        differenceOfDigits = length1 - length2;
    } else if (length2 > length1) {
        greaterNum = num2;
        smallerNum = num1;
        differenceOfDigits = length2 - length1;
    }
    for (size_t i = 0; i < differenceOfDigits; ++i) {
        smallerInt.push('0');
    }
    for (char i : greaterNum) {
        greaterInt.push(i);
    }
    for (char i : smallerNum) {
        smallerInt.push(i);
    }
    unsigned char smallerStackTop = smallerInt.pop();
    unsigned char greaterStackTop = greaterInt.pop();
    cout << greaterStackTop << endl << smallerStackTop << endl;
    int value = greaterStackTop - smallerStackTop;
    cout << value;
    unsigned char unit;
    cout << endl << "---------" << endl;
    if (value < 0 ) {
        cout << "--------" << endl;
        greaterInt.push((greaterInt.pop() - 1));
        unit = static_cast<unsigned char>(value + 10);
        cout << "--------" << endl;
        cout << unit << endl;
        cout << "--------" << endl;
        finalAns.push(unit);
    } else {
        finalAns.push(value);
    }
    cout << finalAns.top();
    return "";

}

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
    cout << "===========" << endl;
    subtractLargeInts("19547465464", "5555555");

    // Test for Function: (6)


    return 0;
}

#endif /* TASK2_BACKEND_H */
