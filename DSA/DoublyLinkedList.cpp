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
    void insertAtEnd(int value) // insertion at end
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
            P->next = NULL;
            Node *Q = List;
            while (Q->next != NULL)
            {
                Q = Q->next;
            }
            Q->next = P;
            P->prev = Q;
        }
        cout << "Inserted " << value << endl;
    }
    void insertAtSpecificPoint(int value, int position) // insertion at position
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
            Node *Q = List;
            for (int i = 1; i < position - 1; i++)
            {
                Q = Q->next;
            }
            P->next = Q->next;
            P->prev = Q;
            Q->next = P;
            P->next->prev = P;
        }
        cout << "Inserted " << value << endl;
    }
    void deleteFromFront() // deletion at beginning
    {
        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return;
        }
        Node *P = List;
        List = List->next;
        List->prev = NULL;
        delete P;
        cout << "Deleted" << endl;
    }
    void deleteFromEnd() // deletion at end
    {
        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return;
        }
        Node *P = List;
        while (P->next != NULL)
        {
            P = P->next;
        }
        P->prev->next = NULL;
        delete P;
        cout << "Deleted" << endl;
    }
    void deleteFromSpecificPoint(int position) // deletion at position
    {
        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return;
        }
        Node *P = List;
        for (int i = 1; i < position; i++)
        {
            P = P->next;
        }
        P->prev->next = P->next;
        P->next->prev = P->prev;
        delete P;
        cout << "Deleted" << endl;
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
    //countElements() function to count the number of elements in the linked list
    void countElements()
    {
        int count = 0;
        Node *P = List;
        while (P != NULL)
        {
            count++;
            P = P->next;
        }
        cout<<count<<" elements in the linked list"<<endl;
    }

    //searchElement(num) function to search for an element in the linked list
    void searchElement(int num)
    {
        Node *P = List;
        int count = 0;
        while (P != NULL)
        {
            count++;
            if (P->info == num)
            {
                cout << "Element found at position " << count << endl;
                return;
            }
            P = P->next;
        }
        cout << "Element not found" << endl;
    }
       void sortLinkedList(int order)
    {
        Node *P;
        Node *Q;
        P = List;
        Q = P->next;
        if(order == 1)
        {
            while(P->next != NULL)
            {
                while(Q!= NULL)
                {
                    if(Q->info < P->info)
                    {
                        int temp = Q->info;
                        Q->info = P->info;
                        P->info = temp;
                    }
                    Q = Q->next;
                }
                P = P->next;
                Q = P->next;
            }
        }
        else if(order == 2)
        {
            while(P->next != NULL)
            {
                while(Q!= NULL)
                {
                    if(Q->info > P->info)
                    {
                        int temp = Q->info;
                        Q->info = P->info;
                        P->info = temp;
                    }
                    Q = Q->next;
                }
                P = P->next;
                Q = P->next;
            }
        }

        cout<<"\nSorted Linked List!\n";
        displayLinkedList();
    }
    void mergeLists(Node* List2)
    {
        Node *P = List;

        while(P->next != NULL)
        {
            P = P->next;
        }

        P->next = List2;
    }
    void reverseLinkedList()
    {
        Node *P = List;
        Node *Q = NULL;
        Node *R = NULL;

        while(P != NULL)
        {
            R = Q;
            Q = P;
            P = P->next;
            Q->next = R;
        }
        List = Q;
        cout<<"\nReversed Linked List!\n";
        displayLinkedList();
    }
    //Function to return 1st element of the linked list
    void peekPoint()
    {
        cout<<"First Element in the List is: "<< List->info<<endl;
    }
    //Function to return last element of the linked list
    void endPoint()
    {
        Node *P = List;
        while(P->next != NULL)
        {
            P = P->next;
        }
        cout<<"Last Element in the List is: "<< P->info<<endl;
    }
};
int main()
{

    DoublyLinkedList list1;
    DoublyLinkedList list2;
    int userInput,num,point,loc,order;
    bool ans;
    list2.insertAtFront(29);
    list2.insertAtFront(107);
    list2.insertAtFront(99);
    list2.insertAtFront(38);
    list2.insertAtFront(77);
    list2.insertAtFront(66);
    list2.insertAtFront(155);
    list2.displayLinkedList();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    do
    {
        cout<<"1. Insert at Front"<<endl;
        cout<<"2. Delete From Front"<<endl;
        cout<<"3. Insert at End"<<endl;
        cout<<"4. Delete from End"<<endl;
        cout<<"5. Insert at Specific Point"<<endl;
        cout<<"6. Delete from Specific Point"<<endl;
        cout<<"7. Display Linked List"<<endl;
        cout<<"8. Count Elements is Linked List"<<endl;
        cout<<"9. Search Element"<<endl;
        cout<<"10.Sort Linked List"<<endl;
        cout<<"11.First Element in the Linked List"<<endl;
        cout<<"12.Last Element in the Linked List"<<endl;
        cout<<"13.Merg Two Linked Lists"<<endl;
        cout<<"14.Reverse Linked Lists"<<endl;
        cout<<"15.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>userInput;

        switch(userInput)
        {
        case 1:
            cout<<"Enter number: ";
            cin>>num;
            list1.insertAtFront(num);
            break;
        case 2:
            list1.deleteFromFront();
            break;
        case 3:
            cout<<"Enter number: ";
            cin>>num;
            list1.insertAtEnd(num);
            break;
        case 4:
            list1.deleteFromEnd();
            break;
        case 5:
            cout<<"Enter Point to insert AT: ";
            cin>>loc;
            cout<<"Enter number: ";
            cin>>num;
            list1.insertAtSpecificPoint(num,loc);
            break;
        case 6:
            cout<<"Enter Location From Where you want to Delete: ";
            cin>>point;
            list1.deleteFromSpecificPoint(point);
            break;
        case 7:
            list1.displayLinkedList();
            break;
        case 8:
            list1.countElements();
            break;
        case 9:
            cout<<"Enter Element to Search: ";
            cin>>num;
            list1.searchElement(num);
            break;
        case 10:
            cout<<"Press 1 for Ascending Order\nPress 2 for Descending Order\nYour Choice: ";
            cin>>order;
            list1.sortLinkedList(order);
            break;
        case 11:
            list1.peekPoint();
            break;
        case 12:
            list1.endPoint();
            break;
        case 13:
            cout<<"List 1"<<endl;
            list1.displayLinkedList();
            cout<<"List 2"<<endl;
            list2.displayLinkedList();
            list1.mergeLists(list2.List);
            cout<<"Lists Merged"<<endl;
            list1.displayLinkedList();
            break;
        case 14:
            cout<<"Exiting..."<<endl;
            list1.displayLinkedList();
            list1.reverseLinkedList();
            break;
        case 15:
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
        cout<<endl;

    }
    while(userInput != 13);

    return 0;
}