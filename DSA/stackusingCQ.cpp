#include <iostream>
using namespace std;
#define MAX 5

class Queue
{
public:
    int Array[MAX], front, rear;

    Queue()
    {
        front = -1;
        rear = -1;
    }
    // Check if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == MAX - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    // Adding an temp
    void enQueue(int temp)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            Array[rear] = temp;
        }
    }
    // Removing an temp
    int deQueue()
    {
        int temp;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            temp = Array[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            // Q has only one temp,
            // so we reset the queue after deleting it.
            else
            {
                front = (front + 1) % MAX;
            }
            return (temp);
        }
    }

    void display()
    {
        // Function to display status of Circular Queue
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << endl
                 << "elements -> ";
            for (i = front; i != rear; i = (i + 1) % MAX)
                cout << Array[i] << " ";
            cout << Array[i];
            cout<<endl;
        }
    }
    int frontNo()
    {
        return Array[front];
    }
};

class Stack
{
public:
    Queue q;
    void push(int x)
    {
        int size = q.rear;
        q.enQueue(x);
        for (int i = 0; i < size; i++)
        {
            q.enQueue(q.frontNo());
            q.deQueue();
        }
    }
    void pop()
    {
        if (q.isEmpty())
        {
            cout << "Underflow Error" << endl;
            return;
        }
        q.deQueue();
    }
    int top()
    {
        return q.frontNo();
    }
    void print()
    {
        q.display();
    }
};
int main()
{
    Stack s;
    s.push(4);//4
    s.push(1);//1,4
    s.push(2);//2,1,4
    s.push(10);//10,2,1,4
    s.print();
    s.pop();
    s.pop();
    s.print();
    return 0;
}