#include <iostream>
#include <vector>

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

Node *convertArrToLL(const std::vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 1; i < arr.size(); ++i)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *oddEven(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    std::vector<int> arr;
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);

    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);

    return convertArrToLL(arr);
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

    Node *head1 = oddEven(head);

    Node *temp = head1;

    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;

    return 0;
}