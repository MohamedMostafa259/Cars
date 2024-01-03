#ifndef TASK2_BACKEND_H
#define TASK2_BACKEND_H

#include <iostream>
#include "StackList.h"
#include "QueueList.h"
using namespace std;

//(2)
template <typename T>
void copyStack(StackList<T>& s1, StackList<T>& s2) {
    StackList<T> temp;


    while (!s1.isEmpty()) {
        T val = s1.pop();
        s2.push(val);
        temp.push(val);
    }

    while (!temp.isEmpty()) {
        T val = temp.top();
        temp.pop();
        s1.push(val);;
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
    // used size_t instead of int to avoid narrowing unsigned to signed int (ide recommendation)
    bool negativeNum1 = false, negativeNum2 = true;
    string validNum1, validNum2;
    // Check if the input begins with a negative sign flag
    if (num1[0] == '-')
        negativeNum1 = true;
    if (num2[0] == '-')
        negativeNum2 = false;
    // filtering the strings
    // filter for num1
    for (size_t i = 0; i < num1.length(); i++) { // traversing through num1
        if (num1[i] > '9' || num1[i] <= '0') { // skip any symbols or zeros until you find a valid number
            continue;
        } else {
            for (size_t j = i; j < num1.length(); j++) { // continue traversing from index i to the end of the string
                if (num1[j] >= '0' && num1[j] <= '9') { // include values from 0 to 9 inclusive in validNum1
                    validNum1 += num1[j];
                } else {
                    continue;
                }
            }
            break;
        }
    }
    // filter for num2
    for (size_t i = 0; i < num2.length(); i++) { // traversing through num2
        if (num2[i] > '9' || num2[i] <= '0') { // skip any symbols or zeros until you find a valid number
            continue;
        } else {
            for (size_t j = i; j < num2.length(); j++) { // continue traversing from index i to the end of the string
                if (num2[j] >= '0' && num2[j] <= '9') { // include values from 0 to 9 inclusive in validNum2
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
    // determine the greater string
    if (length1 > length2){
        if (negativeNum1^negativeNum2) {
            if (negativeNum1) negativeValue = true;
        } else {
            if (negativeNum1 & negativeNum2) {
                negativeValue = true;
            }
        }
        greaterNum = validNum1;
        smallerNum = validNum2;
        differenceOfDigits = length1 - length2;
    } else if (length1 < length2) {
        if (negativeNum1^negativeNum2) {
            if (negativeNum2) negativeValue = true;
        } else {
            if (negativeNum1 & negativeNum2) {
                negativeValue = true;
            }
        }
        greaterNum = validNum2;
        smallerNum = validNum1;
        differenceOfDigits = length2 - length1;
    } else if (length1 == length2) { // if the two valid strings are equal in length we need a different way
                                    // to determine the greater number
        for (size_t i = 0; i <= length1; i++) { // traverse through validNum1 for example
            if (i == length1) { // if the two number are exactly equal return zero
                if (negativeNum1^negativeNum2) return "0"; // -x+y or x-y
                else {
                    if (negativeNum1 & negativeNum2) negativeValue = true;
                }
                // find the greater digit and assign them to greaterNum and smallerNum
            } else if (validNum1[i] > validNum2[i]) {
                if(negativeNum1 & negativeNum2) negativeValue = true;
                greaterNum = validNum1;
                smallerNum = validNum2;
                break;
            } else if (validNum1[i] < validNum2[i]) {
                if (negativeNum1^negativeNum2) negativeValue = true; // different
                if (negativeNum1 & negativeNum2) negativeValue = true;
                greaterNum = validNum2;
                smallerNum = validNum1;
                break;
            } else { // if the digit are equal continue
                continue;
            }
        }
    }
    for (size_t i = 0; i < differenceOfDigits; ++i) { // push zeros to the smaller string to be equal in number of digits
        smallerInt.push('0');
    }
    greaterInt.push('0');
    smallerInt.push('0');
    for (char i : greaterNum) { // push greaterNum in a stack
        greaterInt.push(i);
    }
    for (char i : smallerNum) { // push smallerNum in a stack
        smallerInt.push(i);
    }
    unsigned char smallerStackTop;
    unsigned char greaterStackTop;
    unsigned char unit;
    int value;
    if (negativeNum1 ^ negativeNum2) {  // xor bitwise operator "^" for the condition X - (+Y) OR (-X) +Y
        while (!greaterInt.isEmpty()) {
            smallerStackTop = smallerInt.pop();
            greaterStackTop = greaterInt.pop();
            value = greaterStackTop - smallerStackTop;
            if (value < 0 ) {
                greaterInt.push((greaterInt.pop() - 1));
                unit = value + 48 + 10; // 48 to get the exact int value as char
                finalAns.push(unit);
            } else {
                finalAns.push(value + 48);// 48 to get the exact int value as char
            }
        }
        if (negativeValue) // if the flag is true then add a negative sign
            finalReturn = "-";
    } else if (!(negativeNum1 ^ negativeNum2)) { // x-nor bitwise operator for the condition (-X - +Y) or (+X - -Y)
        while (!greaterInt.isEmpty()) {
            smallerStackTop = smallerInt.pop();
            cout << "smaller stack top: " << smallerStackTop << endl;
            greaterStackTop = greaterInt.pop();
            cout << "greater stack top: " << greaterStackTop << endl;
            value = (greaterStackTop - 48) + (smallerStackTop - 48);
            cout << "value : " << value << endl;
            if (value >= 10) {
                cout << "value is greater than or equal 10" << endl;
                greaterInt.push((greaterInt.pop() + 1));
                cout <<  greaterInt.top() << endl;
                unit = value - 10 + 48; // 48 to get the exact int value as char
                cout << "unit : " << unit << endl;
                finalAns.push(unit);
            } else {
                cout << "201) value: " << value << endl;
                finalAns.push(value + 48);
                cout << finalAns.top() << endl;
            }
            cout << finalReturn << endl;
        }
        if (negativeValue) // if the flag is true then add a negative sign
            finalReturn = "-";
    }

    while (!finalAns.isEmpty()) {
        finalReturn += finalAns.pop(); // pop the digits from the stack and add them to finalReturn
    }
    // Remove initial zeros
    string checkedFinalReturn;
    bool firstChar = false;
    for (char k : finalReturn) {
        if (!firstChar) {
            if (k == '0') {
                continue;
            }else {
                if (k != '-') { // exclude '-' sign
                    firstChar = true;
                }
            }
        }
        checkedFinalReturn += k;
    }
    return checkedFinalReturn;

}

// (6)
template <typename T>
bool moveNthElem(QueueList<T>& q, int n) {
    if (!(0 < n && n <= q.size()))
        return false;
    
    QueueList<T> tmp;
    for (int i = 1; i < n; i++) // n-1 iterations 
        tmp.enqueue(q.front()), q.dequeue();
    
    T target = q.front(); // the nth element
    q.dequeue();

    while (!q.isEmpty())
        tmp.enqueue(q.front()), q.dequeue(); // push the remaining values after the target

    // Now, q is empty
    q.enqueue(target); // put the nth element at the first
    while (!tmp.isEmpty())
        q.enqueue(tmp.front()), tmp.dequeue(); // push the remaining values

    return true;
}

//(7)
void reverseQueue(QueueList<int>& q) {
    StackList<int> s;
    while (!q.isEmpty()) {
        s.push(q.front());
        q.dequeue();
    }
    while (!s.isEmpty()) {
        q.enqueue(s.top());
        s.pop();
    }
}

#endif /* TASK2_BACKEND_H */
