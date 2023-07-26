#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string address;
    Node* prev;
    Node* next;
    Node(string addr)
    {
        address = addr;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;
    Node* current;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }
    void visitAddress(string addr)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->address == addr)
            {
                current = temp;
                cout << temp->address << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Available" << endl;
    }
    void moveToNext()
    {
        if (current == NULL || current->next == NULL)
        {
            cout << "Not Available" << endl;
            return;
        }
        current = current->next;
        cout << current->address << endl;
    }

    void moveToPrev()
    {
        if (current == NULL || current->prev == NULL)
        {
            cout << "Not Available" << endl;
            return;
        }
        current = current->prev;
        cout << current->address << endl;
    }
};
int main()
{
    DoublyLinkedList d;
    string address;
    while (cin >> address && address != "end")
    {
        Node* newNode = new Node(address);
        if (d.head == nullptr)
        {
            d.head = newNode;
            d.tail = newNode;
            d.current = newNode;
        }
        else
        {
            d.tail->next = newNode;
            newNode->prev = d.tail;
            d.tail = newNode;
        }
    }
    int Q;
    cin >> Q;
    string query;
    cin.ignore();
    getline(cin, query);
    d.visitAddress(query.substr(6));
    for (int i = 1; i < Q; i++)
    {
        getline(cin, query);
        if (query.substr(0, 5) == "visit")
        {
            d.visitAddress(query.substr(6));
        }
        else if (query == "next")
        {
            d.moveToNext();
        } 
        else if (query == "prev")
        {
            d.moveToPrev();
        }
    }
    return 0;
}
