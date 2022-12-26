#include <iostream>
using namespace std;

const int MAX = 5;
int F = -1;
int R = -1;
int Q[MAX] = {0};

void insertAtRear(int value)
{
    if(((F == 0) && (R == MAX-1)) || (F==R+1))
    {
        cout<<endl<<"***--OverFlow--***"<<endl;
    }
    else if(F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        Q[R] = value;
        cout<<endl<<"***-- "<<value<<" Inserted at Rear--***"<<endl;
    }
    else if(F!= 0 && R == MAX-1)
    {
        R = 0;
        Q[R] = value;
        cout<<endl<<"***-- "<<value<<" Inserted at Rear--***"<<endl;
    }
    else
    {
        R++;
        Q[R] =  value;
        cout<<endl<<"***-- "<<value<<" Inserted at Rear--***"<<endl;
    }
}
void deleteFromFront()
{
    if(F == -1 && R == -1)
    {
        cout<<endl<<"***--UnderFlow--***"<<endl;
    }
    else if(F == R)
    {
        F = -1;
        R = -1;
        cout<<endl<<"***--Deleted from Front--***"<<endl;
    }
    else if(F == MAX-1)
    {
        F = 0;
        cout<<endl<<"***--Deleted from Front--***"<<endl;
    }
    else
    {
        F++;
        cout<<endl<<"***--Deleted from Front--***"<<endl;
    }
}
void insertAtFront(int value)
{
    if((F==0 && R == MAX-1) || (F == R+1))
    {
        cout<<endl<<"***--OverFlow--***"<<endl;
    }
    else if(F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        Q[R] = value;
        cout<<endl<<"***-- "<<value<<" Inserted at Front--***"<<endl;
    }
    else if(F == 0 && R!= MAX-1)
    {
        F = MAX-1;
        Q[F] = value;
        cout<<endl<<"***-- "<<value<<" Inserted at Front--***"<<endl;
    }
    else
    {
        F--;
        Q[F]= value;
        cout<<endl<<"***-- "<<value<<" Inserted at Front--***"<<endl;
    }
}
void deleteFromRear()
{
    if(F == -1 && R == -1)
    {
        cout<<endl<<"***--UnderFlow--***"<<endl;
    }
    else if(F == R)
    {
        F = -1;
        R = -1;
        cout<<endl<<"***--Deleted from Rear--***"<<endl;
    }
    else if(R == 0)
    {
        R = MAX-1;
        cout<<endl<<"***--Deleted from Rear--***"<<endl;
    }
    else
    {
        R--;
        cout<<endl<<"***--Deleted from Rear--***"<<endl;
    }
}
void PrintQueue()
{
    if(F == -1 && R == -1)
    {
        cout<<endl<<"***--Queue is Empty--***"<<endl;
    }
    else if(F<=R)
    {
        cout<<endl<<"Following are the Elements Present in the Queue!"<<endl;
        for(int i = F; i<R+1; i++)
        {
            cout<<Q[i]<<endl;
        }
    }
    else
    {
        cout<<endl<<"Following are the Elements Present in the Queue!"<<endl;
        for(int i = F; i<MAX; i++)
        {
            cout<<Q[i]<<endl;
        }
        for(int i = 0; i<R+1; i++)
        {
            cout<<Q[i]<<endl;
        }
    }
}
void DisplayMenu()
{
    cout<<endl<<"***--Double Ended Queue Menu--***"<<endl;
    cout<<"1. Insert at Rear"<<endl;
    cout<<"2. Delete from Front"<<endl;
    cout<<"3. Insert at Front"<<endl;
    cout<<"4. Delete from Rear"<<endl;
    cout<<"5. Print Queue"<<endl;
    cout<<"6. Exit"<<endl;
}
int main()
{
    int choice;
    int value;
    while(1)
    {
        DisplayMenu();
        cout<<endl<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<endl<<"Enter the Value to be Inserted at Rear: ";
                cin>>value;
                insertAtRear(value);
                break;
            case 2:
                deleteFromFront();
                break;
            case 3:
                cout<<endl<<"Enter the Value to be Inserted at Front: ";
                cin>>value;
                insertAtFront(value);
                break;
            case 4:
                deleteFromRear();
                break;
            case 5:
                PrintQueue();
                break;
            case 6:
                exit(0);
            default:
                cout<<endl<<"***--Invalid Choice--***"<<endl;
        }
    }
    return 0;
}
