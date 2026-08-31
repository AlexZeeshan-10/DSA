#include <iostream>
#include <stack>
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
    Stack(Extra space) approach
    Time Complexity:O(n)
    Space Complexity: O(n)
*/
Node *stackRev(Node *head)
{
    if (head == nullptr)
        return nullptr;

    std::stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        ;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

/*
    Better approach
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node *revBetter(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;
    
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

/*
    Recursive Approach
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
Node *recRev(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = recRev(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
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

    head = recRev(head);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";

    return 0;
}