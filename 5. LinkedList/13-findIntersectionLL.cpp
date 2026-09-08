#include <iostream>
#include <map>

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

Node *intersectionNodeBrute(Node *head1, Node *head2)
{
    std::map<Node *, int> mpp;
    Node *temp = head1;

    while (temp)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;

        temp = temp->next;
    }

    return nullptr;
}

int main()
{
    int n;
    std::cin >> n;

    Node *head1 = nullptr;
    Node *tail1 = nullptr;

    while (n--)
    {
        int x;
        std::cin >> x;
        Node *temp = new Node(x);
        if (head1 == nullptr)
        {
            head1 = temp;
            tail1 = temp;
        }

        else
        {
            tail1->next = temp;
            tail1 = tail1->next;
        }
    }

    int n;
    std::cin >> n;

    Node *head2 = nullptr;
    Node *tail2 = nullptr;

    while (n--)
    {
        int x;
        std::cin >> x;
        Node *temp = new Node(x);
        if (head2 == nullptr)
        {
            head2 = temp;
            tail2 = temp;
        }

        else
        {
            tail2->next = temp;
            tail2 = tail2->next;
        }
    }
}