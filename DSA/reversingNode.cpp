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
    // Reverse of a node in a singly Linked List
    void reverseNode()
    {
        Node *p = List;
        Node *q = NULL;
        Node *r = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        List = q;
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
    cout << "Reversing Node.....";
    cout << endl;
    list1.reverseNode();
    list1.displayLinkedList();

    return 0;
}
