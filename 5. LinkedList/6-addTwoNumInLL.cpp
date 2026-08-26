#include <iostream>
#include <vector>
#include <algorithm>

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

Node *CreateLL(int x)
{
    if (x == 0)
        return new Node(0);

    std::vector<int> arrx;
    while (x)
    {
        arrx.push_back(x % 10);
        x /= 10;
    }

    Node *head = new Node(arrx[0]);
    Node *mover = head;
    for (size_t i = 1; i < arrx.size(); ++i)
    {
        Node *temp = new Node(arrx[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *current = dummyNode;
    Node *t1 = l1;
    Node *t2 = l2;
    int carry = 0;

    while (t1 != nullptr || t2 != nullptr)
    {
        int sum = carry;
        if (t1)
            sum += t1->data;
        if (t2)
            sum += t2->data;
        Node *sumNode = new Node(sum % 10);
        carry = sum / 10;
        current->next = sumNode;
        current = current->next;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    if (carry)
    {
        Node *leftCarry = new Node(carry);
        current->next = leftCarry;
    }

    Node *result = dummyNode->next;
    delete dummyNode;
    return result;
}

int main()
{
    int n1, n2;
    std::cin >> n1;
    Node *l1 = CreateLL(n1);

    std::cin >> n2;
    Node *l2 = CreateLL(n2);

    Node *head = addTwoNumbers(l1, l2);
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << "->";
        temp = temp->next;
    }
    std::cout << "nullptr";

    return 0;
}