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

Node *sortAll(Node *head)
{
    if (head == nullptr)
        return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else if (temp->data == 2)
            cnt2++;
        else
            return head;

        temp = temp->next;
    }

    temp = head;
    while (cnt0--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (cnt1--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (cnt2--)
    {
        temp->data = 2;
        temp = temp->next;
    }

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
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    head = sortAll(head);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}