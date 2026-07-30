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
