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
    Brute approach
    Time complexity = O(2*length)
    Space complexity = O(1)
*/
Node *delNodeBrute(Node *head, int n)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

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

// Main function
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