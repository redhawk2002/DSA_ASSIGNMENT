#include<iostream>
using namespace std;

void Push_Rear(int arr[], int front[], int rear[], int lbound, int ubound, int item, int index) {
    if (front[index] == -1 && rear[index] == -1) {
        front[index] = lbound;
        rear[index] = lbound;
        arr[rear[index]] = item;
    }
    else if (rear[index] == ubound)
        cout << "Overflow Condition. No element cannot be added." << endl;
    else {
        rear[index]++;
        arr[rear[index]] = item;
    }
}

void Push_Front(int arr[], int front[], int rear[], int lbound, int ubound, int item, int index) {
    if (front[index] != lbound) {
        if (front[index] == -1 && rear[index] == -1) {
            front[index] = lbound;
            rear[index] = lbound;
            arr[rear[index]] = item;
        }
        else {
            front[index];
            arr[front[index]] = item;
        }
    }
    else {
        cout << "Overflow Condition. No element can be further added in this queue." << endl;
    }
}


void Pop_Front(int arr[], int front[], int rear[], int lbound, int ubound, int index) {
    if (front[index] == -1 && rear[index] == -1)
        cout << "Underflow Condition. No element can be deleted." << endl;
    else if (front[index] == rear[index] || front[index] == ubound) {
        front[index] = -1;
        rear[index] = -1;
    }
    else {
        front[index]++;
    }
}

void Pop_Rear(int arr[], int front[], int rear[], int lbound, int ubound, int index) {
    if (front[index] == -1 && rear[index] == -1)
        cout << "Underflow Condition. No element can be deleted." << endl;
    else if (front[index] == rear[index] || rear[index] == lbound) {
        front[index] = -1;
        rear[index] = -1;
    }
    else
        rear[index]--;
}

void Display(int arr[], int front[], int rear[], int index) {
    int i;
    if (front[index] == -1 && rear[index] == -1)
        cout << "Queue is Empty. No elements can be displayed." << endl;
    else {
        cout << "Elements in the Queue: ";
        for (int i = front[index]; i <= rear[index]; i++)
            cout << arr[i] << "  ";
        cout << "\n";
    }
}

int main() {
    int queuesize, qcount, cont;
    cout << "Enter the size of the queue: ";
    cin >> queuesize;
    int arrsize = 4 * queuesize;
    int front[4], rear[4];
    int p, q, r, s;
    for (int i = 0; i < 4; i++) {
        front[i] = -1;
        rear[i] = -1;
    }
    p = (arrsize - 1) % queuesize;
    q = p + queuesize;
    r = q + queuesize;
    s = r + queuesize;
    int arr[arrsize];
    int choice, val;
    while (true) {
        cout << "Please select an option from the menu." << endl;
        cout << "Press (1) to add an element in the rear of the queue." << endl;
        cout << "Press (2) to add an element in the front of the queue." << endl;
        cout << "Press (3) to delete element from the front of queue. " << endl;
        cout << "Press (4) to delete element from the rear of queue." << endl;
        cout << "Press (5) to display all elements from the queues." << endl;
        cout << "Press (6) to return to exit the program." << endl;
        cout << "Please select your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                while (true) {
                    cout << "Select the queue you wish to input the element: " << endl;
                    cout << "1.First Queue\n2.Second Queue\n3.Third Queue\n4.Fourth Queue\n5.Return to main menu." << endl;
                    cout << "Your choice: ";
                    cin >> qcount;
                    switch(qcount) {
                        case 1:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Rear(arr, front, rear, 0, p, val, 0);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 2:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Rear(arr, front, rear, p + 1, q, val, 1);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 3:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Rear(arr, front, rear, q + 1, r, val, 2);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 4:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Rear(arr, front, rear, r + 1, s, val, 3);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 5:
                            goto Menu1;
                            break;
                    }
                }
                Menu1:
                break;
			case 2:
				while (true) {
                    cout << "Select the queue you wish to input the element: " << endl;
                    cout << "1.First Queue\n2.Second Queue\n3.Third Queue\n4.Fourth Queue\n5.Return to main menu." << endl;
                    cout << "Your choice: ";
                    cin >> qcount;
                    switch(qcount) {
                        case 1:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Front(arr, front, rear, 0, p, val, 0);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 2:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Front(arr, front, rear, p + 1, q, val, 1);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 3:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Front(arr, front, rear, q + 1, r, val, 2);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 4:
                            while (true) {
                                cout << "Enter the element you wish to input: ";
                                cin >> val;
                                Push_Front(arr, front, rear, r + 1, s, val, 3);
                                cout << "If you wish to continue, press (1), else (0): ";
                                cin >> cont;
                                if (cont == 1)
                                    continue;
                                else
                                    break;
                            }
                            break;
                        case 5:
                            goto Menu2;
                            break;
                    }
                }
                Menu2:
                break;
            case 3:
                while (true) {
                    cout << "Which queue would you like to delete: " << endl;
                    cout << "1.First Queue\n2.Second Queue\n3.Third Queue.\n4.Fourth Queue\n5.Return to main menu." << endl;
                    cout << "Your choice: ";
                    cin >> qcount;
                    switch (qcount) {
                        case 1:
                            Pop_Front(arr, front, rear, 0, p, 0);
                            cout << "\nDeletion from first queue was successful." << endl;
                            break;
                        case 2:
                            Pop_Front(arr, front, rear, p + 1, q, 1);
                            cout << "\nDeletion from second queue was successful." << endl;
                            break;
                        case 3:
                            Pop_Front(arr, front, rear, q + 1, r, 2);
                            cout << "\nDeletion from first third was successful." << endl;
                            break;
                        case 4:
                            Pop_Front(arr, front, rear, r + 1, s, 3);
                            cout << "\nDeletion from fourth queue was successful." << endl;
                            break;
                        case 5:
                            goto Menu3;
                            break;
                    }
                }
                Menu3:
                break;
            case 4:
                while (true) {
                    cout << "Which queue would you like to delete: " << endl;
                    cout << "1.First Queue\n2.Second Queue\n3.Third Queue.\n4.Fourth Queue\n5.Return to main menu." << endl;
                    cout << "Your choice: ";
                    cin >> qcount;
                    switch (qcount) {
                        case 1:
                            Pop_Rear(arr, front, rear, 0, p, 0);
                            cout << "\nDeletion from first queue was successful." << endl;
                            break;
                        case 2:
                            Pop_Rear(arr, front, rear, p + 1, q, 1);
                            cout << "\nDeletion from second queue was successful." << endl;
                            break;
                        case 3:
                            Pop_Rear(arr, front, rear, q + 1, r, 2);
                            cout << "\nDeletion from first third was successful." << endl;
                            break;
                        case 4:
                            Pop_Rear(arr, front, rear, r + 1, s, 3);
                            cout << "\nDeletion from fourth queue was successful." << endl;
                            break;
                        case 5:
                            goto Menu4;
                            break;
                    }
                }
                Menu4:
                break;
            case 5:
                cout << "\nFirst Queue: ";
                Display(arr, front, rear, 0);
                cout << "\nSecond Queue: ";
                Display(arr, front, rear, 1);
                cout << "\nThird Queue: ";
                Display(arr, front, rear, 2);
                cout << "\nFourth Queue";
                Display(arr, front, rear, 3);
                cout << "\n\n";
                break;
            case 6:
                goto Menu5;
                break;
        }
    }
    Menu5:
    return 0;
}
