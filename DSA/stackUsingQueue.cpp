#include <iostream>
using namespace std;

const int MAX = 5;
int F = -1;
int R = -1;
int Q[MAX];

void EnQueue(int value)
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
        cout<<endl<<"***-- "<<value<<" Inserted--***"<<endl;
    }
    else if(F!= 0 && R == MAX-1)
    {
        R = 0;
        Q[R] = value;
        cout<<endl<<"***-- "<<value<<" Inserted--***"<<endl;
    }
    else
    {
        R++;
        Q[R] =  value;
        cout<<endl<<"***-- "<<value<<" Inserted--***"<<endl;
    }
}
void DeQueue()
{
    if(F == -1 && R == -1)
    {
        cout<<endl<<"***--UnderFlow--***"<<endl;
    }
    else if(F == R)
    {
        F = -1;
        R = -1;
        cout<<endl<<"***--Deleted--***"<<endl;
    }
    else if(F == MAX-1)
    {
        F = 0;
        cout<<endl<<"***--Deleted--***"<<endl;
    }
    else{
        F++;
        cout<<endl<<"***--Deleted--***"<<endl;
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
        for(int i = F; i<R+1;i++)
        {
            cout<<Q[i]<<endl;
        }
    }
    else
    {
        cout<<endl<<"Following are the Elements Present in the Queue!"<<endl;
        for(int i = F; i<MAX;i++)
        {
            cout<<Q[i]<<endl;
        }
        for(int i = 0; i<R+1;i++)
        {
            cout<<Q[i]<<endl;
        }
    }
}
int main()
{
   
    return 0;
}
