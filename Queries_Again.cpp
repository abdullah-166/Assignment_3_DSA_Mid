#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node* prev;
    Node* next;
    Node(int value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
void printLeft(Node* head)
{
    cout << "L -> ";
    Node* newnode = head;
    while (newnode != NULL)
    {
        cout << newnode->value << " ";
        newnode = newnode->next;
    }
    cout << endl;
}
void printRight(Node* tail)
{
    cout << "R -> ";
    Node* newnode = tail;
    while (newnode != NULL)
    {
        cout << newnode->value << " ";
        newnode = newnode->prev;
    }
    cout << endl;
}
void insertAtIndex(Node*& head, Node*& tail, int index, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else if (index == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node* current = head;
        int currentIndex = 0;
        while (current != NULL && currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }
        if (current == NULL && currentIndex == index)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else if (current != NULL)
        {
            newNode->prev = current->prev;
            current->prev->next = newNode;
            newNode->next = current;
            current->prev = newNode;
        }
        else
        {
            cout << "Invalid" << endl;
            delete newNode;
            return;
        }
    }
    printLeft(head);
    printRight(tail);
}
int main()
{
    int Q;
    cin >> Q;
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < Q; i++)
    {
        int X, V;
        cin >> X >> V;
        if (X > i)
        {
            cout << "Invalid" << endl;
            continue;
        }
        insertAtIndex(head, tail, X, V);
    }
    return 0;
}
