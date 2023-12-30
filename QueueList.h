#ifndef QueueList_H
#define QueueList_H

#include <iostream>
#include <list>
using namespace std;

template <typename T>
class QueueList {
        private:
        list<T> elements;

        public:
        void enqueue(const T& value) {
            elements.push_back(value);
        }

        void dequeue() {
            if (!isEmpty()) {
                elements.pop_front();
            }
        }

        T front() {
            if (!isEmpty()) {
                return elements.front();
            } else {
                return T();
            }
        }

        bool isEmpty() {
            return elements.empty();
        }

        void clear() {
            elements.clear();
        }

        int size() {
            return elements.size();
        }
};

#endif //QueueList_H
