#ifndef TASK2_BACKEND_H
#define TASK2_BACKEND_H

#include <iostream>
#include "StackList.h"
#include "QueueList.h"
using namespace std;

//(2)
template <typename T>
void copyStack(StackList<T>& s1, StackList<T>& s2) {

    while (!s1.isEmpty()) {
       T temp=s1.top();
        s1.pop();
        s1.push(temp);
    }

    while (!s2.isEmpty()) {
        T temp=s2.top();
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
    // used size_t instead of int to avoid narrowing unsigned to signed int (ide recommendation)
    bool negativeNum1 = false, negativeNum2 = false;
    string validNum1, validNum2;
    // Check if the input begins with a negative sign flag
    if (num1[0] == '-')
        negativeNum1 = true;
    if (num2[0] == '-')
        negativeNum2 = true;
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
        greaterNum = validNum1;
        smallerNum = validNum2;
        differenceOfDigits = length1 - length2;
    } else if (length1 < length2) {
        negativeValue = true;
        greaterNum = validNum2;
        smallerNum = validNum1;
        differenceOfDigits = length2 - length1;
    } else if (length1 == length2) { // if the two valid strings are equal in length we need a different way
                                    // to determine the greater number
        for (size_t i = 0; i <= length1; i++) { // traverse through validNum1 for example
            if (i == length1) { // if the two number are exactly equal return zero
                return "0";
                // find the greater digit and assign them to greaterNum and smallerNum
            } else if (validNum1[i] > validNum2[i]) {
                greaterNum = validNum1;
                smallerNum = validNum2;
                break;
            } else if (validNum1[i] < validNum2[i]) {
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
    if (negativeNum1 ^ negativeNum2) {  // xor bitwise operator "^" for the condition X + (-Y) OR (-X) + Y
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
    } else if (!(negativeNum1 ^ negativeNum2)) { // x-nor bitwise operator for the condition -X-Y or X+Y
        // Not handled as it is not requested in the project
        return "Not handled\n";
    }

    while (!finalAns.isEmpty()) {
        finalReturn += finalAns.pop(); // pop the digits from the stack and add them to finalReturn
    }
    return finalReturn;

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
