#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Queue {
    public:
       vector<int>data;
       int Capacity;
       Queue() {
           int ArraySize;
           cout << "Enter the size of the Queue: "; 
           cin >> ArraySize;
           Capacity = ArraySize;
       }
};

Queue Q1;
Queue Q2;
Queue Q3;

bool FullQueue(Queue * Q) {
    return Q->data.size() == Q->Capacity;
}

bool IsEmpty() {
    return Q1.data.size() == 0;
}

bool IsFull() {
    return Q3.data.size() == Q3.Capacity;
}

void Enqueue() {
    if (IsFull()) {
        cout << "The Queue is Filled." << endl;
    }
    else {
        if (!FullQueue(&Q1)) {
            int input;
            cout << "Enter the Person number: "; 
            cin >> input;
            Q1.data.push_back(input);
        }
        else if (!FullQueue(&Q2)) {
            int input;
            cout << "Enter the person number: "; 
            cin >> input;
            Q2.data.push_back(input);
        }
        else {
            int input;
            cout << "Enter the person number: "; 
            cin >> input;
            Q3.data.push_back(input);
        }
    }
}

void DisplayQueue() {
    cout << "The First Queue Patients (Queue Beginning): ";
    for (auto i = Q1.data.begin(); i != Q1.data.end(); i++) {
        cout << *i << "  ";
    }
    cout << "\n";
    cout << "The Second Queue Patients (Queue Beginning): ";
    for (auto i = Q2.data.begin(); i != Q2.data.end(); i++) {
        cout << *i << "  ";
    }
    cout << "\n";
    cout << "The Third Queue Patients (Queue Beginning): ";
    for (auto i = Q3.data.begin(); i != Q3.data.end(); i++) {
        cout << *i << "  ";
    }
    cout << "\n";
}

void Dequeue() {
    if (IsEmpty()) {
        cout << "The Queue is completely empty. There are no patients." << endl;
        return;
    }
    int eject = Q1.data.front();
    cout << "The Person with number: " << eject << " is removed from the queue." << endl;
    auto i = remove(Q1.data.begin(), Q1.data.end(), eject);
    Q1.data.pop_back();
    while (Q1.data.size() < Q1.Capacity && !Q2.data.empty()) {
        int eject = Q2.data.front(); //eject = x1
        Q1.data.push_back(Q2.data.front());
        auto i = remove(Q2.data.begin(), Q2.data.end(), eject);
        if (!Q2.data.empty()) {
            Q2.data.pop_back();
        }
        while (Q2.data.size() < Q2.Capacity &&! Q3.data.empty()) {
            int eject = Q3.data.front();
            Q2.data.push_back(Q3.data.front());
            auto i = remove(Q3.data.begin(), Q3.data.end(), eject);
            if (!Q3.data.empty()) {
                Q3.data.pop_back();
            }
        }
    }
}

int main() {
    int choice{0};
    cout << "Welcome to the Vaccination Centre!" << endl;
    while (choice != 7) {
        cout << "Press (1) for inserting a Patient into the Queue." << endl;
        cout << "Press (2) to dequeue a Patient from the Queue." << endl;
        cout << "Press (3) to Display all the three Queues." << endl;
        cout << "Press (4) to check the vaccancy of the Vaccination Centre." << endl;
        cout << "Press (5) to check if the Vaccination centre is Filled." << endl;
        cout << "Press (6) to Display the current line." << endl;
        cout << "Press (7) to exit the program." << endl;
        cin >> choice;
        switch(choice) {
            case 1:
            Enqueue();
            choice = 1;
            break;

            case 2:
            Dequeue();
            choice = 2;
            break;

            case 3: 
            DisplayQueue();
            choice = 3;
            break;

            case 4:
            if (IsEmpty()) {
                cout << "The Queue is empty at the moment." << endl;
            }
            else {
                cout << "The Queue is not empty at the moment." << endl;
            }
            choice = 4; 
            break;

            case 5:
            if (IsFull()) {
                cout << "All the seats in the Queue are occupied." << endl;
            }
            else
               cout << "There are few remaining seats in the queue. Queue is not completely full yet." << endl;
            choice = 5;
            break;

            case 6:
            DisplayQueue();
            choice = 6;
            break;

            case 7: 
            exit(0);
            choice = 7;
            break;

            default:
            cout << "Invalid Choice. Please input a choice from the above options." << endl;
        }
    }
    return 0;
}
