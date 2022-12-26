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
    }
    else if(F!= 0 && R == MAX-1)
    {
        R = 0;
        Q[R] = value;
    }
    else
    {
        R++;
        Q[R] =  value;
    }
}
int DeQueue()
{
    int a;
    if(F == -1 && R == -1)
    {
        cout<<endl<<"***--UnderFlow--***"<<endl;
    }
    else if(F == R)
    {
        a = Q[F];
        F = -1;
        R = -1;
        return a;

    }
    else if(F == MAX-1)
    {
        a = Q[F];
        F = 0;
        return a;
    }
    else{
        a = Q[F];        F++;
    return a;
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
        for(int i = F; i<R+1;i++)
        {
            cout<<Q[i]<<endl;
        }
    }
    else
    {
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
// Function to implement Traffic Light using Queue
void TrafficLight(){
    int i = 1;
    while(i<5){
        EnQueue(i);
        i++;
    }
    for(int i = 0; i<12; i++){
        int a = DeQueue();
        cout<<a<<endl;
        EnQueue(a);
    }
}
int main()
{
    TrafficLight();
    return 0;
}
