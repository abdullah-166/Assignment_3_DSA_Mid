#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node* next;
    Node* previous;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};
void remove_duplicates(Node* head)
{
    Node* newnode = head;
    while (newnode != NULL)
    {
        Node* newnode1 = newnode->next;
        while (newnode1 != NULL)
        {
            if (newnode1->value == newnode->value)
            {
                Node* duplicate = newnode1;
                newnode1->previous->next = newnode1->next;
                if (newnode1->next != NULL)
                {
                    newnode1->next->previous = newnode1->previous;
                }
                newnode1 = newnode1->next;
                delete duplicate;
            }
            else
            {
                newnode1 = newnode1->next;
            }
        }
        newnode = newnode->next;
    }
}
void print_list(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    int minValue = INT_MAX;
    Node* newnode = head;
    while (newnode != NULL)
    {
        if (newnode->value < minValue)
            minValue = newnode->value;
        newnode = newnode->next;
    }
    int count[1001] = {0};
    newnode = head;
    while (newnode != NULL)
    {
        count[newnode->value]++;
        newnode = newnode->next;
    }
    for (int i = minValue; i <= 1000; i++)
    {
        if (count[i] > 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                cout << i << " ";
            }
        }
    }
}
int main()
{
    int value;
    Node* head = NULL;
    Node* tail = NULL;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    remove_duplicates(head);
    print_list(head);
    Node* current = head;
    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
