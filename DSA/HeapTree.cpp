#include <iostream>
using namespace std;

#define SIZE 100
int heap[SIZE];
int heapSize = 0;
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
void insertion(int value){
    if(heapSize == SIZE){
        cout << "Heap is full" << endl;
        return;
    }
    heapSize++;
    heap[heapSize-1] = value;
    for(int i = heapSize-1; i != 0 && heap[parent(i)] < heap[i];){
        int temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;
        i = parent(i);
    }
}





// Function to delete root node
void deletion(){
    if(heapSize == 0){
        cout << "Heap is empty" << endl;
        return;
    }
    heap[0] = heap[heapSize-1];
    cout<<"\n"<<heap[0]<<" is Deleted\n\n";
    heapSize--;
    for(int i = 0; i < heapSize;){
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l < heapSize && heap[l] > heap[i])
            largest = l;
        if(r < heapSize && heap[r] > heap[largest])
            largest = r;
        if(largest != i){
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        }
        else
            break;
    }
}
void printHeap(){
    for(int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}
int main (){
    //Menu
    int choice, value;
    while(true){
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Print Heap" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                insertion(value);
                break;
            case 2:
                deletion();
                break;
            case 3:
                printHeap();
                break;
            case 4:
                exit(1);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
