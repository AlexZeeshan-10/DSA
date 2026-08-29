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
        
    }
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
}