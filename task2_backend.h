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
    while (!greaterInt.isEmpty()) {
        unsigned char smallerStackTop = smallerInt.pop();
        unsigned char greaterStackTop = greaterInt.pop();
        // cout << greaterStackTop << endl << smallerStackTop << endl;
        int value = greaterStackTop - smallerStackTop;
        // cout << value << endl;
        unsigned char unit;
        if (value < 0 ) {
            greaterInt.push((greaterInt.pop() - 1));
            // cout << greaterInt.top() << endl;
            unit = value + 58;
            // cout << unit << endl;
            finalAns.push(unit);
        } else {
            finalAns.push(value + 48);
        }
    }
    string finalReturn;
    while (!finalAns.isEmpty()) {
        finalReturn += finalAns.pop();
    }
    return finalReturn;

}

// (6)




#endif /* TASK2_BACKEND_H */
