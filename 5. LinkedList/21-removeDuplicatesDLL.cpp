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

int main(){
    
}