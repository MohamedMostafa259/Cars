#ifndef TASK1_BACKEND_H
#define TASK1_BACKEND_H

#include <iostream>
#include <algorithm>

using namespace std;

class CarNode {
public:
    string make;
    string model;
    int carsNum{};
    CarNode* next;
    CarNode() : next(0) {}
    CarNode(const string& mk, const string& mod, CarNode* in = 0) : make(mk), model(mod), next(in) {
        carsNum = 1;
    }
};

class SortedUniL {
private:
    CarNode* head {};
    CarNode* tail {};
    CarNode* processSearch(const string &make, const string &model) {

        string makeLower = make;
        string modelLower = model;

        transform(makeLower.begin(), makeLower.end(), makeLower.begin(), ::tolower);
        transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);

        CarNode *temp = head;
        while (temp != nullptr) {

            if (temp->make == makeLower && temp->model == modelLower) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
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

    void remove(const string& make, const string& model) {
        CarNode * temp = this->processSearch(make, model);
        if (temp) {
            temp->carsNum--;
            cout << "One car removed successfully!" << endl;
        } else {
            cout << "Car not found!" << endl;
        }
    }
    void search(const string& make, const string& model) {
        CarNode * temp = processSearch(make, model);
        if (temp) {
            cout << "Number of cars found: " << temp->carsNum << endl;
        } else {
            cout << "Car not found!" << endl;
        }
    }
};

#endif /* TASK1_BACKEND_H */
