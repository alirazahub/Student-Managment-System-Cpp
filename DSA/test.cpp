#include <iostream>
using namespace std;
// implement a heap tree using array

class HeapTree
{
    int *arr;
    int size;
    int capacity;
    int capac;
public:
    HeapTree(int cap)
    {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    //Function to swap two elements
    void swapp(int a, int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void insert(int key)
    {
        if(size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }
        size++;
        arr[size-1] = key;
        for(int i = size-1; i != 0 && arr[parent(i)] < arr[i];)
        {
            swapp(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void deletee(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l < size && arr[l] > arr[i])
            largest = l;
        if(r < size && arr[r] > arr[largest])
            largest = r;
        if(largest != i)
        {
            swapp(arr[i], arr[largest]);
            deletee(largest);
        }
    }
    int extractMax()
    {
        if(size <= 0)
            return INT_MIN;
        if(size == 1)
        {
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size-1];
        size--;
        deletee(0);
        return root;
    }
    void print()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    HeapTree h(11);
    h.insert(13);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.print();
    cout << h.extractMax() << endl;
    h.print();
    return 0;
}
