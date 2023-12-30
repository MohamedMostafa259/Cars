#ifndef TASK1_BACKEND_H
#define TASK1_BACKEND_H

#include <iostream>
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
public:

    void insert(const string& make, const string& model) {
        string makeLower = make;
        string modelLower = model;
        for (char & c: makeLower) {
            c = tolower(c);
        }
        for (char & c: modelLower) {
            c = tolower(c);
        }
        if (!head) // empty
            head = tail = new CarNode(makeLower, modelLower);

        else {
            CarNode* cur, *prv;
            for (cur = head, prv = nullptr; cur; prv = cur, cur = cur->next) {
                if (cur->make == makeLower && cur->model == modelLower) {
                    cur->carsNum++;
                    return;
                }
                else if (makeLower < cur->make || (cur->make == makeLower && modelLower < cur->model)) {
                    CarNode* node = new CarNode(makeLower, modelLower);
                    if (prv) prv->next = node;
                    else head = node;
                    node->next = cur;
                    return;
                }
            }
            prv->next = tail = new CarNode(makeLower, modelLower); // if NOT inserted, makeLower a new tail
        }
    }

    void search(const string &make, const string &model) {
        string makeLower = make;
        string modelLower = model;
        for (char & c: makeLower) {
            c = tolower(c);
        }
        for (char & c: modelLower) {
            c = tolower(c);
        }
        CarNode *temp = head;
        while (temp != nullptr) {

            if (temp->make == makeLower && temp->model == modelLower) {
                cout << "Number of cars found: " << temp->carsNum << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Car not found!" << endl;
    }

    void remove(const string& make, const string& model) {
        string makeLower = make;
        string modelLower = model;
        for (char & c: makeLower) {
            c = tolower(c);
        }
        for (char & c: modelLower) {
            c = tolower(c);
        }
        CarNode *current = head;
        CarNode *prev = nullptr;

        while (current != nullptr) {
            if (current->make == makeLower && current->model == modelLower) {
                break;
            }
            prev = current;
            current = current->next;
        }

        if (current) {
            current->carsNum--;
            cout << "One car removed successfully!" << endl;
        } else {
            cout << "Car not found!" << endl;
        }
        if (current->carsNum == 0) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;

        }

    }

};

#endif /* TASK1_BACKEND_H */
