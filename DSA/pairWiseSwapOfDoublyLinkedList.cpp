#include<iostream>
using namespace std;
class DoublyLinkedList
{
    public:
    struct Node
    {
        int info;
        Node *next;
        Node *prev;
    };
    Node *List = NULL; // header pointer
    void insertAtFront(int value) // insertion at beginning
    {
        Node *P;
        if (List == NULL)
        {
            P = new Node;
            P->info = value;
            P->next = NULL;
            P->prev = NULL;
            List = P;
        }
        else
        {
            P = new Node;
            P->info = value;
            P->next = List;
            P->prev = NULL;
            List->prev = P;
            List = P;
        }
        cout << "Inserted " << value << endl;
    }
    //Pair wise swap elements of a Doubly Linked List
    void pairWiseSwap()
    {
        Node *q = List;
        while (q != NULL && q->next != NULL)
        {
            int temp = q->info;
            q->info = (q->next)->info;
            (q->next)->info = temp;
            q = q->next->next;
        }
    }
    void displayLinkedList() // display linked list
    {
        if (List == NULL)
        {
            cout << "No node to print" << endl;
            return;
        }
        Node *P;
        P = List;
        while (P != NULL)
        {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }

};
int main()
{

    DoublyLinkedList list1;
    int userInput,num,point,loc,order;
    bool ans;
    list1.insertAtFront(29);
    list1.insertAtFront(107);
    list1.insertAtFront(99);
    list1.insertAtFront(38);
    list1.insertAtFront(77);
    list1.insertAtFront(66);
    list1.insertAtFront(155);
    list1.displayLinkedList();
    cout<<endl;
    cout<<endl;
    list1.pairWiseSwap();
    cout<<endl;
    cout<<endl;
    list1.displayLinkedList();


    return 0;
}