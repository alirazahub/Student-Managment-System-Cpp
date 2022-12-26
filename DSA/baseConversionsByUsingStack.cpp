#include <iostream>

using namespace std;
const int MAX =100;
int stack[MAX];
int top = -1;

bool isEmpty(){
if(top == -1)
    return 1;
else
    return 0;
}
bool isFull(){
if(top == MAX-1)
    return 1;
else
    return 0;
}
void push(int num){
if(isFull()){
    cout<<endl<<"Error! ***OverFlow***"<<endl;
}
else{
    top++;
    stack[top] = num;
}
}

void pop(){
if(isEmpty()){
    cout<<endl<<"Error! ***--UnderFlow--***"<<endl;
}
else{
    top--;
}
}
int main(){
    int number;
    int base;
    cout<<"Enter the Number in Decimal: ";
    cin>>number;
    cout<<"In which base you want to convert it? ";
    cin>>base;

    while(number>0){
       int rem = number%base;
       push(rem);
       number /= base;
    };
    cout<<endl<<"Number in base "<<base<<" is : ";
    for(int i = top; i>=0;i--){
    cout<<stack[i]<<" ";
}
return 0;
}
