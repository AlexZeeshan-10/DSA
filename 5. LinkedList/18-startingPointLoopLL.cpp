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

Node *detectCycleBrute(Node *head)
{
    Node *temp = head;
    std::unordered_map<Node *, int> mpp;

    while (temp)
    {
        mpp[temp] = 1;
        temp = temp->next;
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
    }
    return nullptr;
}

Node *detectCycleBetter(Node *head){
    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return nullptr;
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
            tail = temp;
        }
    }
}