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

/*
    Better approach
    Time complexity: O(length)
    Space complexity: O(1)
*/
Node *delNodeBetter(Node *head, int n)
{
    Node *dummyNode = new Node(-1);
    dummyNode->next = head;

    Node *fast = dummyNode;
    Node *slow = dummyNode;

    while (n--)
        fast = fast->next;

    if (fast == nullptr)
    {
        Node *newNode = head->next;
        delete head;
        return newNode;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;

    delete delNode;

    Node *newHead = dummyNode->next;
    delete dummyNode;

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