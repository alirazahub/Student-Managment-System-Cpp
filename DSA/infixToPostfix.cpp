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

// To verify the Opening and Closing Brackets
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

//Checking precedence of Operators
int checkPrec(char c)
{
    if(c == '^')
        return 3;
    else if ( c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
}

int main()
{
    bool isBalanced;
    string expression;
    cout<<"Enter the Infix Expression: ";
    cin>>expression;
    string postFix="";

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
                isBalanced = false;
            }
            char ch = pop();
            bool check = verify(ch,i);
            if(check == false)
            {
                isBalanced = false;
            }
        }
    }
    if(!isEmpty())
    {
        isBalanced = false;
    }
    else
    {
        isBalanced = true;
    }


    if (isBalanced)
    {
        // Reading Expression Character by Character

        for(auto i:expression)
        {
            //In Case if symbols are Opening Pranthesis Push to the stack
            if (i == '[' ||i == '{'||i == '(')
            {
                push(i);
            }

            //In case Symbols are Operators Checking Precedence and Work according to Requirement
            else if (i == '^')
            {
                int pre1 = checkPrec(i);
                char a = stack[top];
                if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
                {
                    int pre2 = checkPrec(a);
                    if(pre1>pre2)
                    {
                        push(i);
                    }
                    else
                    {
                        char pp = pop();
                        postFix+=pp;
                        push(i);
                    }
                }
                else
                {
                    push(i);
                }
            }
            else if (i == '/')
            {
                int pre1 = checkPrec(i);
                char a = stack[top];
                if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
                {
                    int pre2 = checkPrec(a);
                    if(pre1>pre2)
                    {
                        push(i);
                    }
                    else
                    {
                        char pp = pop();
                        postFix+=pp;
                        push(i);
                    }
                }
                else
                {
                    push(i);
                }
            }
            else if (i == '*')
            {
                int pre1 = checkPrec(i);
                char a = stack[top];
                if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
                {
                    int pre2 = checkPrec(a);
                    if(pre1>pre2)
                    {
                        push(i);
                    }
                    else
                    {
                        char pp = pop();
                        postFix+=pp;
                        push(i);
                    }
                }
                else
                {
                    push(i);
                }
            }
            else if (i == '+')
            {
                int pre1 = checkPrec(i);
                char a = stack[top];
                if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
                {
                    int pre2 = checkPrec(a);
                    if(pre1>pre2)
                    {
                        push(i);
                    }
                    else
                    {
                        char pp = pop();
                        postFix+=pp;
                        push(i);
                    }
                }
                else
                {
                    push(i);
                }
            }
            else if (i == '-')
            {
                int pre1 = checkPrec(i);
                char a = stack[top];
                if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
                {
                    int pre2 = checkPrec(a);
                    if(pre1>pre2)
                    {
                        push(i);
                    }
                    else
                    {
                        char pp = pop();
                        postFix+=pp;
                        push(i);
                    }
                }
                else
                {
                    push(i);
                }
            }
            //In Case if symbols are Closing Pranthesis then pop all the
            // Elements and print with Postfix expression untill the matching prenthesis

            else if (i == ']' || i =='}' || i ==')')
            {
                if(i==']')
                {
                    bool x = true;
                    while(x)
                    {
                        if(stack[top]=='[')
                        {
                            x= false;
                            pop();
                        }
                        else
                        {
                            char pp = pop();
                            postFix+= pp;
                        }

                    };
                }
                if(i=='}')
                {
                    bool x = true;
                    while(x)
                    {
                        if(stack[top]=='{')
                        {
                            x= false;
                            pop();
                        }
                        else
                        {
                            char pp = pop();
                            postFix+= pp;
                        }

                    };
                }
                if(i==')')
                {
                    bool x = true;
                    while(x)
                    {
                        if(stack[top]=='(')
                        {
                            x= false;
                            pop();
                        }
                        else
                        {
                            char pp = pop();
                            postFix+= pp;
                        }

                    };
                }
            }
            else
                postFix+=i;
        }

        // If End of Expression Occur but Stack is not Empty then Add all the stack elements to Postfix Expression
        if(top!=-1)
        {
            for(int i = top; i>=0; i--)
            {
                char a = pop();
                postFix+=a;
            }
        }
        cout<<"Postfix Expression of "<<expression<<" is "<<postFix;
    }
    else
    {
        cout<<"Equation is not Balanced so Conversion is Not Possible! ";
        return 0;
    }

    return 0;
}
