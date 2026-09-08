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

Node *collisionPoint(Node *t1, Node *t2, int d)
{
    while (d--)
    {
        t2 = t2->next;
    }
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

Node *intersectionNodeBetter(Node *head1, Node *head2)
{
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

    if (n1 < n2)
        return collisionPoint(head1, head2, n2 - n1);
    else
        return collisionPoint(head2, head1, n1 - n2);
    
    return nullptr;
}

Node *intersectionNodeOptimal(Node *head1, Node*head2){
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    
    Node *t1 = head1, *t2 = head2;
    
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if (t1 == nullptr) t1 = head2;
        if (t2 == nullptr) t2 = head1;
        
    }
    return t1;
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