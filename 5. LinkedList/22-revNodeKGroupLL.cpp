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

Node *findKthNode(Node *temp, int k)
{
    k--;

    while (temp && k > 0)
    {
        temp = temp->next;
        k--;
    }

    return temp;
}

Node *reverseLL(Node *head)
{
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    Node *temp = head;

    while (temp)
    {
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }

    return prevNode;
}

Node *revKGroup(Node *head, int k)
{
    Node *temp = head;
    Node *prevNode = nullptr;

    while (temp)
    {
        Node *kNode = findKthNode(temp, k);

        if (kNode == nullptr)
            break;

        Node *nextNode = kNode->next;
        kNode->next = nullptr;

        reverseLL(temp);

        if (temp == head)
            head = kNode;
        else
            prevNode->next = kNode;

        temp->next = nextNode;

        prevNode = temp;
        temp = nextNode;
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

    head = revKGroup(head, k);

    temp = head;
    std::cout << "nullptr <-> ";
    while (temp)
    {
        std::cout << temp->val << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}