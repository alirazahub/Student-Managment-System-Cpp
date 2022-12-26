#include <iostream>

using namespace std;
const int MAX = 100;
int stack[MAX];
int top = -1;

bool isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
bool isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
void push(int num)
{
    if(isFull())
    {
        cout<<endl<<"Error! ***OverFlow***"<<endl;
    }
    else
    {
        top++;
        stack[top] = num;
        cout<<endl<<"Value Pushed Successfully!"<<endl;
    }
}

void pop()
{
    if(isEmpty())
    {
        cout<<endl<<"Error! ***--UnderFlow--***"<<endl;
    }
    else
    {
        cout<<endl<<"Value "<<stack[top]<< " Poped Successfully!"<<endl;
        top--;
    }
}
int main()
{
    push(10);
    push(20);
    pop();
    pop();
    push(30);

    for(int i = top; i>=0; i--)
    {
        cout<<stack[i]<<" ";
    }

    return 0;
}
