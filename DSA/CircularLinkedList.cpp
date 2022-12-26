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
    Node* P;
    Node* Q;
    Node* temp;

    void insertAtFront(int value)
    {
        if(List == NULL)
        {
            P = new Node;
            P->info = value;
            List = P;
            P->next = List;
        }
        else
        {
            Q = new Node;
            Q = List;
            while(Q->next!=List)
            {
                Q = Q->next;
            }
            P  = new Node;
            P->info = value;
            P->next = List;
            List = P;
            Q->next = List;
        }
        cout<<"Inserted "<<value<<endl;
        displayLinkedList();
    }

    void insertAtEnd (int value)
    {
        if(List == NULL)
        {
            P = new Node;
            P->info = value;
            List = P;
            P->next = List;
        }
        else
        {
            Q = List;
            while(Q->next != List)
            {
                Q = Q->next;
            }
            P = new Node;
            P->info = value;
            P->next = List;
            Q->next = P;
        }
        cout<<"Inserted "<<value<<endl;
        displayLinkedList();
    }

    void insertAtSpecificPoint(int InsertableValue,int PointValue)
    {
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
            while(Q->next != List)
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
        displayLinkedList();
    }


    void deleteFromFront()  // deletion at beginning
    {
        if(List == NULL)
        {
            cout<<"\nNo node to delete in linked list"<<endl;
            return;
        }
        else
        {
            P = List;
            while(P->next !=List){
                P=P->next;
            }
            Q = List;
            List = Q->next;
            P->next = List;

            int x = Q->info;
            delete(Q);
            cout<<"Deleted "<<x<<endl;
        }
        displayLinkedList();
    }

      void deleteFromEnd()  // deletion From End
    {
        P = List;
        Q = List;
        if(List == NULL)
        {
            cout<<"\nNo node to delete in linked list"<<endl;
            return;
        }
        else if(P->next == List)
        {
            int x = P->info;
            List = NULL;
            cout<<"Deleted "<<x<<endl;
        }
        else
        {
            while(Q->next != List)
            {
                P = Q;
                Q = Q->next;
            }
            P ->next = List;
            int x = Q->info;
            delete(Q);
            cout<<"Deleted "<<x<<endl;
        }
        displayLinkedList();
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
            while(P->next != List)
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
        displayLinkedList();
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

        void endPoint()  // This show the end Node
    {
        if(List == NULL)
        {
            cout<<"No node to display in linked list"<<endl;
            return;
        }
        else
        {
            P = List;
            while(P->next !=List)
            {
                P = P->next;
            }
            Q = P;
            cout<<"Last Element in the Linked List is: "<<Q->info<<endl;
        }
    }

    int countElements()
    {
        int Count = 0;
        if(List = NULL){
            return 0;
        }
        temp = List;
        do{
            Count++;
            temp = temp->next;
        }while(temp!=List);
        return Count;
    }
    void displayLinkedList()  // display linked list
    {
        cout<<"\n\n";
        if(List == NULL)
        {
            cout<<"No node to print"<<endl;
            return;
        }

        P = List;
        cout<<"Linked List Contains:"<<endl;

        do
        {
            cout<<P->info<<" ";
            P = P-> next;
        }
        while(P != List);
        cout<<endl<<endl;
        cout<<"\n\n";
    }
    void searchElement(int value)
    {
        temp = List;
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
};
int main()
{

    LinkedList list1;
    LinkedList list2;
    int userInput,num,point,loc,order;
    bool ans;
    list2.insertAtFront(99);
    list2.insertAtFront(88);
    list2.insertAtFront(77);
    list2.insertAtFront(66);
    list2.insertAtFront(55);
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
        cout<<"14.Exit"<<endl;
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
            cout<< list1.countElements()<<" elements are present in the Linked List"<<endl;
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
