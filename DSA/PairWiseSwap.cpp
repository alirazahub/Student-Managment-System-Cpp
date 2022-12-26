#include <iostream>

using namespace std;

class LinkedList
{
public:
    struct Node
    {
        int info;
        Node *next;
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
            List = P;
        }
        else
        {
            P = new Node;
            P->info = value;
            P->next = List;
            List = P;
        }
        cout << "Inserted " << value << endl;
    }

    // Function for pairwise swapping of elements
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
        cout << "Linked List Contains:" << endl;

        while (P != NULL)
        {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl
             << endl;
    }
};

int main()
{

    LinkedList list1;
    list1.insertAtFront(1);
    list1.insertAtFront(2);
    list1.insertAtFront(3);
    list1.insertAtFront(4);
    list1.insertAtFront(5);
    list1.insertAtFront(6);
    list1.displayLinkedList();
    cout << endl;
    cout << endl;
    cout << "PairWise Swaping.....";
    cout << endl;
    list1.pairWiseSwap();
    list1.displayLinkedList();

    return 0;
}
