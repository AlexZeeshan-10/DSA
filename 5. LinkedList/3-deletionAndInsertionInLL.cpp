#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
        : data(data1), next(next1) {}

    Node(int data1)
        : data(data1), next(nullptr) {}
};

Node *convertArrToLL(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
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
    if (head == nullptr)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteKthEle(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
        return deleteHead(head);
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteEle(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (head->data == k)
        return deleteHead(head);
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int k)
{
    return new Node(k, head);
}

Node *insertTail(Node *head, int k)
{
    if (head == NULL)
        return new Node(k);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(k);
    return head;
}

Node *insertAtKthPosition(Node *head, int k, int ele)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(ele);
        else
            return NULL;
    }
    if (k == 1)
        return new Node(ele, head);
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *x = new Node(ele, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeVal(Node *head, int val, int ele)
{
    if (head == NULL)
        return NULL;
    if (head->data == val)
        return new Node(ele, head);

    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(ele, temp->next);
            temp->next = x;
            return head;
        }
        temp = temp->next;
    }
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

    // head = deleteHead(head);

    // head = deleteTail(head);

    // int k;
    // std::cin >> k;

    // head = deleteEle(head, k);

    // head = insertTail(head, k);

    // For testing insertBeforeVal
    int val;
    std::cin >> val;
    int ele;
    std::cin >> ele;
    // head = insertAtKthPosition(head, k, ele);
    head = insertBeforeVal(head, val, ele);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}