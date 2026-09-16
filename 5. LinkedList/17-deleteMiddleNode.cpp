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

Node *deleteMiddleBrute(Node *head)
{
    if (head->next == nullptr)
        return nullptr;

    if (head->next->next == nullptr)
    {
        Node *t = head->next;
        head->next = nullptr;
        delete t;
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    Node *front = head->next;
    Node *prev = nullptr;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        front = front->next;
        if (prev == nullptr)
            prev = head;
        else
            prev = prev->next;
    }

    if (fast->next == nullptr)
    {
        prev->next = prev->next->next;
        delete slow;
        return head;
    }

    slow->next = slow->next->next;
    delete front;

    return head;
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

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}