#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

Node *convertArrToLL(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 1; i < arr.size(); ++i)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    free (temp);
    return head;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    Node *head = convertArrToLL(arr);

    head = deleteHead(head);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}