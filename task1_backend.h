#ifndef TASK1_BACKEND_H
#define TASK1_BACKEND_H

#include <iostream>
using namespace std;

class CarNode {
public: 
    string make;  
    string model; 
    int carsNum;  
    CarNode* next; 
    CarNode() {next = 0;}  
    CarNode(const string& mk, const string& mod, CarNode* in = 0) : make(mk), model(mod), next(in) {
        carsNum = 1;
    }
};

class SortedUniL {
private:
    CarNode* head {};
    CarNode* tail {};

public:

    void insert(const string& make, const string& model) {
        if (!head) // empty
            head = tail = new CarNode(make, model);

        else {
            CarNode* cur, *prv;
            for (cur = head, prv = nullptr; cur; prv = cur, cur = cur->next) {
                if (cur->make == make && cur->model == model) {
                    cur->carsNum++;
                    return;
                }
                else if (make < cur->make || (cur->make == make && model < cur->model)) { 
                    CarNode* node = new CarNode(make, model);
                    if (prv) prv->next = node;
                    else head = node;
                    node->next = cur;
                    return;
                }
            } 
            prv->next = tail = new CarNode(make, model); // if NOT inserted, make a new tail
        }
    }

};

#endif /* TASK1_BACKEND_H */