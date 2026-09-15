#include <iostream>
#include <unordered_map>

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

bool hasCycle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    Node *temp = head;
    std::unordered_map<Node *, int> mpp;
    while (temp)
    {
        if (mpp.find(temp) == mpp.end())
            return true;
        else
            mpp[temp] = 1;

        temp = temp->next;
    }
    return false;
}

bool hasCycleBetter(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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
}