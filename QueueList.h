#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <list>
using namespace std;

template <typename T>
class TemplateQueueList {
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
};

#endif //QUEUE_H
