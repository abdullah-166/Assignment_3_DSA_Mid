#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* next;
        Node(int value)
        {
            this->value=value;
            this->next=NULL;
        }
};
void insert(Node* &head, int val)
{
    Node* newnode = new Node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
}
void print(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
void remove(Node* head) 
{
    Node* newnode = head;
    Node* temp = NULL;
    Node* Unique = head;
    int tempData;
    while (newnode != NULL)
    {
        temp = newnode->next;
        while (temp != NULL)
        {
            if (newnode->value > temp->value) 
            {
                tempData = newnode->value;
                newnode->value = temp->value;
                temp->value = tempData;
            }
            temp = temp->next;
        }
        newnode = newnode->next;
    }
    while (Unique != NULL && Unique->next != NULL)
     {
        if (Unique->value == Unique->next->value)
         {
            Node* duplicate = Unique->next;
            Unique->next = duplicate->next;
            delete duplicate;
        } 
        else
        {
            Unique = Unique->next;
        }
    }
    Unique = head;
    while (Unique != NULL) 
    {
        cout << Unique->value << " ";
        Unique = Unique->next;
    }
}
int main()
{
    Node *head = NULL;
    int val;
    while(val!=-1)
    {
        cin>>val;
        if(val==-1)
        {
            break;
        }
        insert(head,val);
    }
    remove(head);
    return 0;
}