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

/*Brute approach to sort the Linked List
    Time complexity = O(2n) Two traversal, One for count another to place elements
    Space complexity = O(1)
*/
Node *sortAllBrute(Node *head)
{
    if (head == nullptr)
        return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else if (temp->data == 2)
            cnt2++;
        else
            return head;

        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }

        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }

        else
        {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}

/* Better approach to sort the Linked List
    Time complexity = O(n) one pass traversal
    Space complexity = O(1)
*/
Node *sortAllBetter(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = (twoHead->next) ? twoHead->next : nullptr;
    two->next = nullptr;

    Node *ans = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return ans;
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

    head = sortAllBetter(head);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}