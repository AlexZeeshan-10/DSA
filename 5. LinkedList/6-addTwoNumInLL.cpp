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
    std::vector<int> arrx;
    while (x)
    {
        arrx.push_back(x % 10);
        x /= 10;
    }

    std::reverse(arrx.begin(), arrx.end());
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

Node *addTwoNumbers(Node* l1, Node *l2){
    
}

int main()
{
    int n1, n2;
    std::cin >> n1;
    Node *l1 = CreateLL(n1);

    std::cin >> n2;
    Node *l2 = CreateLL(n2);
}