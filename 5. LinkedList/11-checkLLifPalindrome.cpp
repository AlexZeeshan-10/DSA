#include <iostream>
#include <algorithm>
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

Node *reverse(Node *curr)
{
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

bool isPalindromeBetter(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverse(slow->next);

    Node *first = head, *second = newHead;
    while (second)
    {
        if (first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
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

    // std::cout << (isPalindromeBrute(head) == 1 ? "True" : "False");
}