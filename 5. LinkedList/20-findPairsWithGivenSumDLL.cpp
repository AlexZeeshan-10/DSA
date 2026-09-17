#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(Node *prev1, int data1, Node *next1)
        : prev(prev1), data(data1), next(next1) {}

    Node(int data1)
        : prev(nullptr), data(data1), next(nullptr) {}
};

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
            temp->prev = tail;
            tail = temp;
        }
    }
    Node *temp = head;
    std::cout << "nullptr <->";
    while (temp)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}