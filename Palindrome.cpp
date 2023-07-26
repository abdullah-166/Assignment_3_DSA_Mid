#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
bool Palindrome(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    Node* curr = slow;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    Node* first = head;
    Node* second = prevNode;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (Palindrome(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
