#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(Node *prev1, int data1, Node *next1)
        : prev(prev1), data(data1), next(next1) {}

    Node(int data1)
        : prev(nullptr), data(data1), next(nullptr) {}
};

Node *deleteOccurence(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;

            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
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
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    int k;
    std::cin >> k;

    head = deleteOccurence(head, k);

    temp = head;
    std::cout << std::endl << "nullptr <-> ";
    while (temp)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr";

    return 0;
}