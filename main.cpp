#include <iostream>
#include "QueueList.h"
#include "StackList.h"
#include "task1_backend.h"
#include "task2_backend.h"
using namespace std;

/////////// Helper Methods ////////////////

template <class T>
void stack_input(StackList<T>& st) {
    int size;
    cout << "Enter size: ";
    cin >> size;

    if (size <= 0)
        return;
    cout << "Enter Elements: ";
    T input;
    while (size--) {
        cin >> input;
        st.push(input);
    }
}

template <class T>
void queue_input(QueueList<T>& q) {
    int size;
    cout << "Enter size: ";
    cin >> size;

    if (size <= 0)
        return;
    cout << "Enter Elements: ";
    T input;
    while (size--) {
        cin >> input;
        q.enqueue(input);
    }
}

//////////////////////////////////////////

int entry_menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nTasks Menu:\n"
            << "1) Task 1\n"
            << "2) Task 2\n"
            << "3) Exit\n";

        cout << "\nEnter your menu choice [1 - 3]: ";
        cin >> choice;

        if (!(1 <= choice && choice <= 3)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

int task1_menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nTask 1 Menu:\n"
            << "1) Add a Car\n"
            << "2) Remove a Car\n"
            << "3) Search for a Car by Make and Model\n"
            << "4) Display all Cars\n"
            << "5) Exit\n";

        cout << "\nEnter your menu choice [1 - 5]: ";
        cin >> choice;

        if (!(1 <= choice && choice <= 5)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

int task2_menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nTask 2 Menu:\n"
            << "1) Copy a Stack\n"
            << "2) Convert Decimal to Another Base\n"
            << "3) Subtract 2 Big Integers\n"
            << "4) Move Nth Element to Front in a Queue of Strings\n"
            << "5) Reverse Elements of a Queue\n"
            << "6) Exit\n";

        cout << "\nEnter your menu choice [1 - 6]: ";
        cin >> choice;

        if (!(1 <= choice && choice <= 6)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

void task1_execution(SortedUniL& cars) {
    while (true) {
        int choice = task1_menu();
        string make, model;

        if (choice <= 3) {
            cout << "Make and Model: ";
            cin >> make >> model;
        }

        if (choice == 1) 
            cars.insert(make, model);

        else if (choice == 2)
            cars.remove(make, model);

        else if (choice == 3) 
            cars.search(make, model);

        else if (choice == 4)
            cars.print();

        else 
            break;
    }
}

template <class T>
void task2_execution() {
    while (true) {
        int choice = task2_menu();

        if (choice == 1) {
            StackList<T> st1, st2;
            cout << "Enter Stack 1 Data \n";
            stack_input(st1);

            copyStack(st1, st2);
            cout << "Stack 1 has been successfully copied\n";
            
            cout << "Stack 1 Elements: ";
            while (!st1.isEmpty())
                cout << st1.pop() << " ";
            cout << "\n";

            cout << "Stack 2 Elements: ";
            while (!st2.isEmpty())
                cout << st2.pop() << " ";
            cout << "\n";
        }

        else if (choice == 2) {
            int decimal, base;
            cout << "Enter a Decimal Number and a Base: ";
            cin >> decimal >> base;
            string res = convertToNS(decimal, base);
            cout << "Output: " << res << "\n";
        }

        else if (choice == 3) {
            string num1, num2;
            cout << "Enter Two Integer Numbers: ";
            cin >> num1 >> num2;
            string res = subtractLargeInts(num1, num2);
            cout << "Output: " << res << "\n";
        }

        else if (choice == 4) {
            QueueList<T> q;
            cout << "Enter Queue Data \n";
            queue_input(q);

            int idx;
            cout << "Enter Index(1-based index) for the Nth Element: ";
            cin >> idx;

            while (!moveNthElem(q, idx)) {
                cout << "invalid index !! .. try again: ";
                cin >> idx;
            }

            cout << "The Element with Index " << idx << "has been moved to the front successfully\n";
            cout << "Queue Elements After Update: ";
            while (!q.isEmpty())
                cout << q.front() << " ", q.dequeue();
            cout << "\n";
        }
        
        else if (choice == 5) {
            QueueList<T> q;
            cout << "Enter Queue Data \n";
            queue_input(q);

            reverseQueue(q);

            cout << "Queue has been reversed successfully\n";
            cout << "Queue Elements After Update: ";
            while (!q.isEmpty())
                cout << q.front() << " ", q.dequeue();
            cout << "\n";
        }

        else 
            break;
    }
}


void run() {
    SortedUniL cars; // data will be saved even if the user enters Exit from Task 1
    while (true) {
        int choice = entry_menu();
        
        if (choice == 1)
            task1_execution(cars);

        else if (choice == 2) 
            task2_execution<int>(); // we can use any data type instead of "int", 
                                    // but let's use "int" as our desired data type
        else {
            cout << "BYE ..\n";
            break;
        }
    }
}


int main() {

    run();

    // // Test for Function: (2)
    // StackList<int> s1, s2;
    // int n;
    // int value;
    // cout << "Enter number of stack elements:";
    // cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     cout << "Enter value number " << i << ":";
    //     cin >> value;
    //     s1.push(value);
    // }
    // copyStack(s1, s2);
    // s2.reverse();
    // cout << "S2: [";
    // while (!s2.isEmpty()) {
    //     cout << s2.pop();
    //     if (!s2.isEmpty()) {
    //         cout << ",";
    //     }
    // }
    // cout << "]" << endl;

    // // Test for Function: (3)


    // // Test for Function: (4)
    // cout << convertToNS(61, 3) << "\n"; // 2021
    // cout << convertToNS(0, 3) << "\n"; // 0
    // cout << convertToNS(564231, 16) << "\n"; // 89C07
    // cout << convertToNS(564231, 10) << "\n"; // 564231
    // cout << convertToNS(564231, 8) << "\n"; // 2116007
    // cout << convertToNS(564231, 2) << "\n"; // 10001001110000000111
    // cout << convertToNS(125, 18) << "\n"; // 6H
    // cout << convertToNS(125, 1) << "\n"; // Error!! The Allowed Range for Base is [2, 20]

    // // Test for Function: (5)
    // cout << "===========" << endl;
    // cout << "Enter two large Integers to subtract in the form Z = X + Y:\n";
    // string x, y;
    // cout << "X =";
    // cin >> x;
    // cout << "Y =";
    // cin >> y;
    // string z = subtractLargeInts(x, y);
    // cout << "Z = X + Y = " << z << endl;
    // // Test for Function: (6)


    return 0;
}
