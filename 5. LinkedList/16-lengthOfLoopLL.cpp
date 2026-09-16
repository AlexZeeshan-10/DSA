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

int loopLengthBrute(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    std::unordered_map<Node *, int> mpp;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            int val = mpp[temp];
            return cnt - val;
        }
        cnt++;
        mpp[temp] = cnt;
        temp = temp->next;
    }
    return 0;
}

int loopLengthBetter(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast)
    {
        if (fast == slow)
        {
            int cnt = 1;
            fast = fast->next;
            while (fast != slow)
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
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