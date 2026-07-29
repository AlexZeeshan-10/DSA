#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data1, Node *next1, Node *prev1)
        : data(data1), next(next1), prev(prev1) {}

    Node(int data1)
        : data(data1), next(nullptr), prev(nullptr) {}
};

// convert array to a LL
Node *convertArrayToLL(std::vector<int> &arr)
{
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

// convert to a doubly LL
Node *convertToDoublyLL(std::vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// deleting head in a doubly LL
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

// deleting tail in a doubly LL
Node *deleteTail(Node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *prev = temp->prev;
    prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// deleting kth element in a Doubly LL
Node *deleteKthElement(Node *head, int target)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == target)
            break;
        temp = temp->next;
    }
    Node *back = temp->prev;
    Node *front = temp->next;
    if (back == nullptr && front == nullptr)
    {
        delete temp;
        return head;
    }
    else if (back == nullptr)
        return deleteHead(head);
    else if (front == nullptr)
        return deleteTail(head);

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// delete node in a Doubly LL
Node *deleteNode(Node *head, Node *target)
{
    Node *temp = target;
    Node *front = temp->next;
    Node *back = temp->prev;
    if (front == nullptr)
    {
        return deleteTail(head);
    }
    front->prev = back;
    back->next = front;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// Insertion at the head of a doubly LL
Node *insertHead(Node *head, int val)
{
    if (head == nullptr)
        return head = new Node(val);
    Node *temp = head;
    head = new Node(val, temp, nullptr);
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

    Node *head;

    head = convertToDoublyLL(arr);

    int val;
    std::cin >> val;
    head = insertHead(head, val);

    if (head == nullptr)
    {
        std::cout << "nullptr" << std::endl;
        return 0;
    }

    Node *temp = head;
    std::cout << "nullptr <-> ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}