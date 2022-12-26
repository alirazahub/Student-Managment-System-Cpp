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

    // Function to check number is Prime or not
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    // Delete all Prime Nodes from a Linked List
    void deletePrime()
    {
        Node *p = List;
        Node *q = NULL;
        LinkedList temp;
        while (p != NULL)
        {
            if (isPrime(p->info))
            {
                if (p == List)
                {
                    List = List->next;
                    temp.insertAtFront(p->info);
                    delete (p);
                    p = List;
                }
                else
                {
                    q->next = p->next;
                    temp.insertAtFront(p->info);
                    delete (p);
                    p = q->next;
                }
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
        temp.displayLinkedList();
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
    cout << "Deleting Prime Nodes.....";
    cout << endl;
    list1.deletePrime();
    cout << endl;
    cout << endl;
    list1.displayLinkedList();

    return 0;
}
