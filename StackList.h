#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>
#include <list>
using namespace std;

template <typename T>
class StackList {
private:
    list<T> l;

public:
    
    void push(const T& val) {
        l.push_back(val);
    }

    T pop() {
        if (!isEmpty()) {
            T res = l.back();
            l.pop_back();
            return res;
        }
        cout << "Stack is Empty!!\n";
        return T(); // return default value
    }

    T popFront() {
        if (!isEmpty()) {
            T res = l.front();
            l.pop_front();
            return res;
        }
        cout << "Stack is Empty!!\n";
        return T(); // return default value
    }

    T top() {
        if (!isEmpty()) 
            return l.back();
        cout << "Stack is Empty!!\n";
        return T(); // return default value
    }

    bool isEmpty() {
        return l.empty();
    }

    void clear() {
        l.clear();
    }
};

#endif /* STACK_LIST_H */
