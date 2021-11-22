#include <iostream>
using namespace std;

int T;

class round_robin{
public:
    int PID;
    int CPU_time;
    round_robin *next;

};

round_robin *head=NULL;

void insert()
{
    int x; //PID
    int y; //CPU_time

    cout<<"enter PID "<<endl;
    cin>>x;
    round_robin *temp4=head;
    while(temp4!=NULL){
        if(x==temp4->PID){
            cout<<"PID already exist"<<endl;
            return ;
        }
        temp4=temp4->next;
    }

    cout<<"enter CPU_time "<<endl;
    cin>>y;
    round_robin *t=new round_robin();
    t->PID = x;
    t->CPU_time = y;
    t->next = NULL;

    if(head==NULL)
    {
        head = t;
    }

    else
    {
        round_robin *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
            temp->next=t;
    }
}

void process()
{
    if(head==NULL)
    {
        cout<<"there is not process"<<endl;
        return;
    }
    round_robin *temp=head;
    if(temp->CPU_time>0)
    {
        temp->CPU_time = temp->CPU_time-T;
        if(head->next == NULL)
        {
            return;
        }
        round_robin *temp1 = head;
        while(temp1->next!=NULL)
        {
            temp1 = temp1->next;
        }
        head = temp->next;
        temp1->next = temp;
        temp->next = NULL;
    }
    else
    {
        round_robin *temp2=head;
        head=head->next;
        printf("Process ID %d has been deleted from the list\n",temp2->PID);
        delete temp2;
    }
}

void print()
{
    round_robin *temp = head;
    if(head == NULL)
    {
      printf("All processes are completed\n");
      return ;
    }
    while(temp!=NULL)
    {
        cout<<"User ID  "<<temp->PID;
        cout<<"\tCPU Time  "<<temp->CPU_time<<endl;
        temp=temp->next;
    }
}


int main()
{
   cout<<"enter the quantum time "<<endl;
   cin>>T;

   int choice{0};
   cout << "Welcome to the round robin scheduling!" << endl;
   while (choice != 4)
   {
        cout << "Press (1) for inserting a Process." << endl;
        cout << "Press (2) to execute the process." << endl;
        cout << "Press (3) to Display the current status." << endl;
        cout << "Press (4) to exit the program" << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
            insert();
            //choice = 1;
            break;

            case 2:
            process();
            //choice = 2;
            break;

            case 3:
            print();
            //choice = 3;
            break;


            case 4:
            exit(0);
            //choice = 4;
            break;

            default:
            cout << "Invalid Choice. Please input a choice from the above options." << endl;
        }
    }
    return 0;
}
