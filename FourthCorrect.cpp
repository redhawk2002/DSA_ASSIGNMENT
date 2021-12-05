#include<stdio.h>
#include<stdlib.h>

void Push_Rear (int *, int, int *, int *);
void Push_Front(int *, int, int *, int *);
void Pop_Rear  (int *, int, int *, int *);
void Pop_Front (int *, int, int *, int *);
void DisplayQueue(int *, int, int, int);
void InputRQueue(int *, int, int *, int *);
void OutputRQueue(int *, int , int *, int *);

int main() {
    int *queue[4], qsize[4];
    int front[4], rear[4];
    int qnum, choice;
    int size;
    int cond;
    int menu;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    for (int i = 0; i < 4; i++) {
        qsize[i] = size;
        queue[i] = (int*)malloc(size * sizeof(int));
        front[i] = -1;
        rear[i] = -1;
    }
    Menu:
        printf("Press (1) if you wish to work on any queue.\n");
        printf("Press (2) to display all the queues values in the array.\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);
        if (menu == 2) {
            printf("Elements in the first queue: ");
            DisplayQueue(queue[0], qsize[0], front[0], rear[0]);
            printf("Elements in the second queue: ");
            DisplayQueue(queue[1], qsize[1], front[1], rear[1]);
            printf("Elements in the third queue: ");
            DisplayQueue(queue[2], qsize[2], front[2], rear[2]);
            printf("Elements in the fourth queue: ");
            DisplayQueue(queue[3], qsize[3], front[3], rear[3]);
        }
        else {
            printf("Press (0) to edit first queue.\n");
            printf("Press (1) to edit second queue.\n");
            printf("Press (2) to edit third queue.\n");
            printf("Press (3) to edit fourth queue.\n");
            printf("Enter queue number: ");
            scanf("%d", &qnum);
            int op = 0;
            printf("Press (1) to an input restricted DQueue.\n");
            printf("Press (2) to an output restricted DQueue.\n");
            printf("Please enter your choice: ");
            scanf("%d", &op);
            switch(op) {
                case 1:
                    InputRQueue(queue[qnum], qsize[qnum], &front[qnum], &rear[qnum]);
                    break;
                case 2:
                    OutputRQueue(queue[qnum], qsize[qnum], &front[qnum], &rear[qnum]);
                    break;
                default:
                    printf("Invalid choice entered.\n");
            }
            printf("\nPress (1) to return to first menu.\n");
            printf("Press (2) to exit the program.\n");
            printf("Enter your choice: ");
            scanf("%d", &cond);
            if (cond == 1)
                goto Menu;
            else if (cond == 2)
                exit(0);
        }
}

void InputRQueue(int *arr, int size, int *f, int *r) {
    int op = 0;
    do {
        printf("Press (1) to Enqueue from rear end.\n");
        printf("Press (2) to Dequeue from front end.\n");
        printf("Press (3) to Dequeue from rear end.\n");
        printf("Press (4) to display the queue.\n");
        printf("Press (5) to exit the program.\n");
        printf("Please input your choice: ");
        scanf("%d", &op);
            switch(op) {
            case 1:
                Push_Rear(arr, size, f, r);
                break;
            case 2:
                Pop_Front(arr, size, f, r);
                break;
            case 3:
                Pop_Rear(arr, size, f, r);
                break;
            case 4:
                DisplayQueue(arr, size, *f, *r);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice selected.\n");
        }
    }
    while (op != 5);
}

void OutputRQueue(int *arr, int size, int *f, int *r) {
    int op = 0;
    do {
        printf("Press (1) to Enqueue from rear end.\n");
        printf("Press (2) to Enqueue from front end.\n");
        printf("Press (3) to Dequeue from rear end.\n");
        printf("Press (4) to display the queue.\n");
        printf("Press (5) to exit the program.\n");
        printf("Please input your choice: ");
        scanf("%d", &op);
            switch(op) {
            case 1:
                Push_Rear(arr, size, f, r);
                break;
            case 2:
                Push_Front(arr, size, f, r);
                break;
            case 3:
                Pop_Rear(arr, size, f, r);
                break;
            case 4:
                DisplayQueue(arr, size, *f, *r);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice selected.\n");
        }
    }
    while (op != 5);
}

void Push_Rear(int *arr, int size, int *f, int *r)
{
    int val;
    if ((*f == 0 && *r == size - 1) || (*f == *r + 1))
    {
        printf("Overflow Condition. No further data can be added into this queue.\n");
        return;
    }
    if (*f == -1)
    {
        *f = 0;
        *r = 0;
    }
    else
    {
        if (*r == size - 1)
            *r = 0;
        else
            *r = *r + 1;
    }
    printf("Input the element for adding in queue : ");
    scanf("%d", &val);
    arr[*r] = val;
}
void Push_Front(int *arr, int size, int *f, int *r)
{
    int val;
    if ((*f == 0 && *r == size - 1) || (*f == *r + 1))
    {
        printf("Overflow Condition. No further data can be added into this queue.\n");
        return;
    }
    if (*f == -1)
    {
        *f = 0;
        *r = 0;
    }
    else
    {
        if (*f == 0)
            *f = size - 1;
        else
            *f = *f - 1;
    }
    printf("Input the element for adding in queue : ");
    scanf("%d", &val);
    arr[*f] = val;
}
void Pop_Front(int *arr, int size, int *f, int *r)
{
    if (*f == -1)
    {
        printf("Underflow Condition. No element can be ejected from the queue.\n");
        return;
    }
    printf("Element has been ejected from queue is : %d\n", arr[*f]);
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        if (*f == size - 1)
            *f = 0;
        else
            *f = *f + 1;
    }
}
void Pop_Rear(int *arr, int size, int *f, int *r)
{
    if (*f == -1)
    {
        printf("Underflow Condition. No element can be ejected from the queue.\n");
        return;
    }
    printf("Element has been ejected from queue is : %d\n", arr[*r]);
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        if (*r == 0)
            *r = size - 1;
        else
            *r = *r - 1;
    }
}
void DisplayQueue(int *arr, int size, int f, int r)
{
    int frontptr = f;
    int rearptr = r;
    if (f == -1)
    {
        printf("NULL (No elements in the queue)\n");
        return;
        }
    if (frontptr <= rearptr)
    {
        while (frontptr <= rearptr)
        {
            printf("%d ", arr[frontptr]);
            frontptr++;
        }
    }
    else
    {
        while (frontptr <= size - 1)
        {
            printf("%d ", arr[frontptr]);
            frontptr++;
        }
        frontptr = 0;
        while (frontptr <= rearptr)
        {
            printf("%d ", arr[frontptr]);
            frontptr++;
        }
    }
    printf("\n");
}
