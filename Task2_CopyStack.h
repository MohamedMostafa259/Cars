#ifndef TASK2_COPYSTACK_H
#define TASK2_COPYSTACK_H

#include <iostream>
#include "QUEUEProject.h"
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


int main() {
    StackList<int> s1;
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3);

    StackList<int> s2;
    copyStack(s1, s2);

    while (!s2.isEmpty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}
#endif //TASK2_COPYSTACK_H
