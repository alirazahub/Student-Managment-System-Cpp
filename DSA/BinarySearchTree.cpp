#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;

};
node * root;
node * insertion(node*root,int x)
{
    if(root==NULL)
    {
        node* p= new node;
        p->info=x;
        p->left=NULL;
        p->right=NULL;
        root=p;
    }
    else if(root->info==x)
    {
        cout<<"discard"<<endl;
    }
    else if(root->info<x)
    {
        root->right=insertion(root->right,x);
    }
    else if(root->info>x)
    {
        root->left=insertion(root->left,x);
    }
    return root;
}
//post order
void displaypost(node*root)
{
    if(root==NULL)
    {
        return;
    }

    displaypost(root->left);
    displaypost(root->right);
    cout<<root->info<<"  ";
}

//pre order
void displaypre(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->info<<"  ";
    displaypre(root->left);
    displaypre(root->right);

}
//in order
void displayin(node*root)
{
    if(root==NULL)
    {
        return;
    }

    displayin(root->left);
    cout<<root->info<<"  ";
    displayin(root->right);

}

node* minValueNode( node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
node* deleteNode( node* root, int x)
{
    if (root == NULL)
        return root;


    if (x < root->info)
        root->left = deleteNode(root->left, x);

    else if (x > root->info)
        root->right = deleteNode(root->right, x);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = minValueNode(root->right);

        root->info = temp->info;

        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}
int main()
{
    root=NULL;
    root=insertion(root,10);
    root=insertion(root,8);
    root=insertion(root,15);
    root=insertion(root,7);
    root=insertion(root,9);
    root=insertion(root,14);
    root=insertion(root,16);
    cout<<"Pre Order "<<endl;
    displaypre(root);
    cout<<endl;
    cout<<"Post Order "<<endl;
    displaypost(root);
    cout<<endl;
    cout<<"In Order "<<endl;
    displayin(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    root = deleteNode(root,8);
    cout<<"Pre Order "<<endl;
    displaypre(root);
    cout<<endl;
    cout<<"Post Order "<<endl;
    displaypost(root);
    cout<<endl;
    cout<<"In Order "<<endl;
    displayin(root);
    cout<<endl;
    cout<<endl;

}