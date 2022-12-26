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
    }
}

int pop()
{
    if(isEmpty())
    {
        cout<<endl<<"Error! ***--UnderFlow--***"<<endl;
    }
    else
    {
        return (stack[top]);
    }
}

//Function to Check Operand
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}

//Function to Check Operator
bool isOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '%')
        return true;

    return false;
}
int evaluate(string postfix)
{
    int result;
    string val = "";
    for (auto i: postfix)
    {
        if (isOperator(i))
        {
            int value;
            int a = pop();
            top--;
            int b = pop();
            top--;
            switch (i)
            {
            case '+':
            {
                value = b + a;
                break;
            }
            case '-':
            {
                value = b - a;
                break;
            }
            case '*':
            {
                value = b * a;
                break;
            }
            case '/':
            {
                value = b / a;
                break;
            }
            case '%':
            {
                value = b % a;
                break;
            }
            case '^':
            {
                value = b ^ a;
                break;
            }
            default:
                break;
            }
            push(value);
        }
        else if(isOperand(i))
        {
            //to Convert char to int forExample '9' to 9

            int num = i-48;
            push(num);
        }
    }
    result = pop();
    return result;
}
int main()
{
    string postfix;
    cout << "Enter the postfix expression: ";
    cin>>postfix;
    int result = evaluate(postfix);
    cout << "Result is: " << result << endl;

    return 1;
}
