#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrayToLinkedList(std::vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLinkedList(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    // basics
    // vector<int> arr = {2, 5, 8, 7};
    // Node *y = new Node(arr[0], nullptr);
    // cout << y->data;

    // Traversing a array into a linkedlist

    // std::vector<int> arr = {12, 5, 8, 7};
    // Node* head = convertArrayToLinkedList(arr);
    // Node* temp = head;
    // while (temp)
    // {
    //     std::cout << temp->data << " -> ";
    //     temp = temp->next;
    // }
    // std::cout << "nullptr" << std::endl;

    // length count of a linked list
    std::vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrayToLinkedList(arr);
    std::cout << lengthOfLinkedList(head);
}