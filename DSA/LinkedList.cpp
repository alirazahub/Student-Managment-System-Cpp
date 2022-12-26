#include<iostream>

using namespace std;

class LinkedList
{
public:
    struct Node
    {
        int info;
        Node* next;
    };

    Node *List = NULL; // header pointer

    // insert node at sorted fashion
    void insertInSortedFashion(int data)
    {
        Node *temp = new Node;
        temp->info = data;
        temp->next = NULL;

        if(List == NULL)
        {
            List = temp;
        }
        else
        {
            Node *p = List;
            Node *q = NULL;

            while(p != NULL && p->info < data)
            {
                q = p;
                p = p->next;
            }

            if(p == List)
            {
                temp->next = List;
                List = temp;
            }
            else
            {
                temp->next = q->next;
                q->next = temp;
            }
        }
    }

    void insertAtFront(int value)  // insertion at beginning
    {
        Node* P;
        if(List == NULL)
        {
            P = new Node;
            P ->info=value;
            P->next = NULL;
            List = P;
        }
        else
        {
            P = new Node;
            P-> info = value;
            P -> next = List;
            List = P;
        }
        cout<<"Inserted "<<value<<endl;
    }

    void insertAtEnd(int value)  //Insert At the END
    {
        Node *P;
        if(List == NULL)
        {
            P = new Node;
            P ->info = value;
            cout<<"Inserted "<<value<<endl;
            P ->next = NULL;
            List = P;
        }
        else
        {
            Node * Q;
            Q = List;
            while(Q ->next != NULL)
            {
                Q = Q ->next;
            }
            P = new Node;
            P -> info = value;
            cout<<"Inserted "<<value<<endl;
            P ->next = NULL;
            Q ->next = P;
        }
    }
    void insertAtSpecificPoint(int InsertableValue,int PointValue)
    {
        Node *P;
        Node *Q;
        Q = List;
        if(List == NULL)
        {
            P = new Node;
            P->info = InsertableValue;
            cout<<InsertableValue<<" is Inserted at the Start cuz List is Empty"<<endl;
            P->next = NULL;
            List = P;
        }
        else
        {
            while(Q->next != NULL)
            {
                if(Q->info == PointValue)
                {
                    P = new Node;
                    P ->info = InsertableValue;
                    cout<<InsertableValue<<" is Inserted at "<<PointValue<<endl;
                    P->next = Q->next;
                    Q->next = P;
                }
                Q = Q->next;
            }
        }
    }

    void deleteFromFront()  // deletion at beginning
    {
        if(List == NULL)
        {
            cout<<"No node to delete in linked list"<<endl;
            return;
        }
        else
        {
            Node *P;
            P = List;
            List = P->next;
            int x = P->info;
            delete(P);
            cout<<"Deleted "<<x<<endl;
        }
    }

    void deleteFromEnd()  // deletion From End
    {
        Node *P;
        Node *Q;
        P = List;
        if(List == NULL)
        {
            cout<<"No node to delete in linked list"<<endl;
            return;
        }
        else if(P->next == NULL)
        {
            int x = P->info;
            P = NULL;
            cout<<"Deleted "<<x<<endl;
        }
        else
        {
            while(P->next != NULL)
            {
                Q = P;
                P = P->next;
            }
            Q ->next = NULL;
            int x = P->info;
            delete(P);
            cout<<"Deleted "<<x<<endl;
        }
    }

    void deleteFromSpecificPoint(int point)
    {
        Node *P;
        Node *Q;
        P = List;
        if(List == NULL)
        {
            cout<<"No node to delete in linked list"<<endl;
            return;
        }
        else
        {
            while(P->next != NULL)
            {
                if(P->info ==point)
                {
                    Q->next = P->next;
                    int x = P->info;
                    delete(P);
                    cout<<x<<" is Deleted from location"<<point<<endl;
                }
                else
                {
                    Q = P;
                    P = P->next;
                }
            }
        }
    }

    void peekPoint()  // This show the First Node
    {
        if(List == NULL)
        {
            cout<<"No node to display in linked list"<<endl;
            return;
        }
        else
        {
            cout<<"First Element in the Linked List is: "<<List->info<<endl;
            return;
        }
    }

    void endPoint()  // This show the First Node
    {
        if(List == NULL)
        {
            cout<<"No node to display in linked list"<<endl;
            return;
        }
        else
        {
            Node *P;
            Node *Q;
            P = List;
            while(P->next !=NULL)
            {
                P = P->next;
            }
            Q = P;
            cout<<"Last Element in the Linked List is: "<<Q->info<<endl;
        }
    }

    void countElements()
    {
        Node *temp;
        int Count = 0;
        temp = List;
        while(temp!=NULL)
        {
            Count++;
            temp = temp->next;
        }
        cout<< Count<<" elements are present in the Linked List"<<endl;
    }

    void displayLinkedList()  // display linked list
    {
        if(List == NULL)
        {
            cout<<"No node to print"<<endl;
            return;
        }

        Node*P;
        P = List;
        cout<<"Linked List Contains:"<<endl;

        while(P != NULL)
        {
            cout<<P->info<<" ";
            P = P-> next;
        }
        cout<<endl<<endl;
    }
    void searchElement(int value)
    {
        Node *temp;
        temp = List;
        Node *Q;
        while(temp!=NULL)
        {
            if(temp ->info == value)
            {
                cout<<"Yes! "<<value<<" is present in the Linked List"<<endl;
                return;
            }
            Q = temp;
            temp = temp->next;
        }
        cout<<"No! "<<value<<" is not present in the Linked List"<<endl;
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
    //Function to reverse the linked list
    void reverseLinkedList()
    {
        Node *P;
        Node *Q;
        Node *Temp;
        P = List;
        Q = NULL;
        Temp = NULL;
        while(P != NULL)
        {
            Temp = Q;
            Q = P;
            P = P->next;
            Q->next = Temp;
        }
        List = Q;
        cout<<"\nReversed Linked List!\n";
        displayLinkedList();
    }
};

int main()
{

    LinkedList list1;
    LinkedList list2;
    int userInput,num,point,loc,order;
    bool ans;
    list2.insertInSortedFashion(29);
    list2.insertInSortedFashion(107);
    list2.insertInSortedFashion(99);
    list2.insertInSortedFashion(38);
    list2.insertInSortedFashion(77);
    list2.insertInSortedFashion(66);
    list2.insertInSortedFashion(155);
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
