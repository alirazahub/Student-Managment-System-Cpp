#include <iostream>

using namespace std;
const int MAX =100;
char stack[MAX];
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
void push(char num)
{
    if(isFull())
    {
        cout<<endl<<"Error! ***OverFlow***"<<endl;
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

char pop()
{
    if(!isEmpty())
    {
        char ch = stack[top];
        top--;
        return ch;
    }
    else
    {
        return 0;
    }
}

bool verify(char open,char close)
{
    if(open == '(')
    {
        char con = ')';
        if(con == close)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(open == '[')
    {
        char con = ']';
        if(con == close)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(open == '{')
    {
        char con = '}';
        if(con == close)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    string expression="[{(A-B)+(C+D)-(E-F)}]";

    for(auto i:expression)
    {
        if(i == '(' || i == '['|| i == '{')
        {
            push(i);
        }
        if(i == ')' || i == ']'|| i == '}')
        {
            if(isEmpty())
            {
                cout<<endl<<"Expression is not Balanced "<<endl;
                return 0;
            }
            char ch = pop();
            bool check = verify(ch,i);
            if(check == false)
            {
                cout<<endl<<"Expression is not Balanced "<<endl;
                return 0;
            }
        }
    }
    if(!isEmpty())
    {
        cout<<endl<<"Expression is not Balanced "<<endl;
        return 0;
    }
    else
    {
        cout<<"Expression is Balanced!";
    }


    return 0;
}
