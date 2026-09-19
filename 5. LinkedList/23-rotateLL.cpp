#include <iostream>

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

public:
    Node(Node *prev1, int val1, Node *next1)
        : prev(prev1), val(val1), next(next1) {}

    Node(int val1)
        : prev(nullptr), val(val1), next(nullptr) {}
};

Node *findNthNode(Node *temp, int k)
{
    int cnt = 1;
    while (temp)
    {
        if (cnt == k)
            return temp;

        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotateLL(Node *head, int k)
{
    if (head == nullptr || k == 0)
        return head;

    int len = 1;
    Node *temp = head;
    while (temp->next)
    {
        len++;
        temp = temp->next;
    }

    if (k % len == 0)
        return head;

    k = k % len;

    temp->next = head;

    Node *newLastNode = findNthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = nullptr;

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
            temp->prev = tail;
            tail = temp;
        }
    }

    Node *temp = head;
    std::cout << "nullptr <-> ";
    while (temp)
    {
        std::cout << temp->val << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    int k;
    std::cin >> k;

    head = rotateLL(head, k);

    temp = head;
    std::cout << "nullptr <-> ";
    while (temp)
    {
        std::cout << temp->val << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}