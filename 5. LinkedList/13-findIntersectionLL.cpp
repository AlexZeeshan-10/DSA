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

Node *collisionPoint(Node *head1, Node *head2, int n){
    
}

Node *intersectionNodeBetter(Node *head1, Node *head2){
    int n1 = 0, n2 = 0;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1)
    {
        n1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        n2++;
        temp2 = temp2->next;
    }
    
    if(n1 < n2)
        return collisionPoint(head1, head2, n2-n1);
    else
        return collisionPoint(head2, head1, n1-n2);
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

    
}