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

Node *delNodeBrute(Node *head, int n)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }

    if (n == cnt)
    {
        Node *delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    int x = cnt - n;
    temp = head;
    while (--x)
    {
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = temp->next->next;

    delete delNode;

    return head;
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

    int k;
    std::cin >> k;

    head = delNodeBrute(head, k);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}