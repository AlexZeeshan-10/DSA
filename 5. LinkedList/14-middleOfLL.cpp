#include <iostream>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
        : data(data), next(next) {}

    Node(int data)
        : data(data), next(nullptr) {}
};

Node *middleNodeBrute(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    cnt = (cnt / 2);

    temp = head;
    while (cnt--)
    {
        temp = temp->next;
    }

    return temp;
}

Node *middleNodeBetter(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
            tail = tail->next;
        }
    }

    

    return 0;
}