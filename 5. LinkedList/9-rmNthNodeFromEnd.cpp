#include <iostream>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
        : data(data1), next(next1) {}

    Node(int data1)
        : data(data1), next(nullptr) {}
};

Node *delNodeBetter(Node *head, int n)
{
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *fast = dummy;
    Node *slow = dummy;

    while (n--)
        fast = fast->next;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;

    delete delNode;

    Node *newHead = dummy->next;
    delete dummy;

    return newHead;
}

int main()
{
    int n;
    std::cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;
    while (n--)
    {
        int x;
        std::cin >> x;
        Node *newNode = new Node(x);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}