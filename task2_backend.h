#ifndef TASK2_BACKEND_H
#define TASK2_BACKEND_H

#include <iostream>
#include "StackList.h"
using namespace std;

template <typename T>
void copyStack(StackList<T>& s1, StackList<T>& s2) {

    while (!s1.isEmpty()) {
       T temp=s1.pop();
        s1.pop();
        s1.push(temp);
    }

    while (!s2.isEmpty()) {
        T temp=s2.pop();
        s2.pop();
        s1.push(temp);
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
    bool negativeNum1, negativeNum2 = false;
    string validNum1, validNum2;
    if (num1[0] == '-')
        negativeNum1 = true;
    if (num2[0] == '-')
        negativeNum2 = true;
    for (size_t i = 0; i < num1.length(); i++) {
        if (num1[i] > '9' || num1[i] <= '0') {
            continue;
        } else {
            for (size_t j = i; j < num1.length(); j++) {
                if (num1[j] >= '0' && num1[j] <= '9') {
                    validNum1 += num1[j];
                } else {
                    continue;
                }
            }
            break;
        }
    }
    for (size_t i = 0; i < num2.length(); i++) {
        if (num2[i] > '9' || num2[i] <= '0') {
            continue;
        } else {
            for (size_t j = i; j < num2.length(); j++) {
                if (num2[j] >= '0' && num2[j] <= '9') {
                    validNum2 += num2[j];
                } else {
                    continue;
                }
            }
            break;
        }
    }
    StackList<unsigned char> greaterInt, smallerInt, finalAns;
    string greaterNum;
    string smallerNum;
    string finalReturn;
    size_t length1 = validNum1.length();
    size_t length2 = validNum2.length();
    size_t differenceOfDigits = 0;
    bool negativeValue = false;
    if (length1 > length2){
        greaterNum = validNum1;
        smallerNum = validNum2;
        differenceOfDigits = length1 - length2;
    } else if (length1 < length2) {
        negativeValue = true;
        greaterNum = validNum2;
        smallerNum = validNum1;
        differenceOfDigits = length2 - length1;
    } else if (length1 == length2) {
        for (size_t i = 0; i <= length1; i++) {
            if (i == length1) {
                return "0";
            } else if (validNum1[i] > validNum2[i]) {
                greaterNum = validNum1;
                smallerNum = validNum2;
            } else if (validNum1[i] < validNum2[i]) {
                greaterNum = validNum2;
                smallerNum = validNum1;
            } else {
                continue;
            }
        }
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
    if (negativeNum1 ^ negativeNum2) {  // xor bitwise operator "^" for the condition X + (-Y) OR (-X) + Y
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

        if (negativeValue)
            finalReturn = "-";
        while (!finalAns.isEmpty()) {
            finalReturn += finalAns.pop();
        }
    } else if (!(negativeNum1 ^ negativeNum2)) { // x-nor bitwise operator for the condition -X-Y or X+Y
        if (negativeNum1 & negativeNum2) {  // if -X-Y == -(X+Y)
            finalReturn = "-";
        }
        // calculate X + Y
        // not handled yet
    }

    return finalReturn;

}
// (6)




#endif /* TASK2_BACKEND_H */
