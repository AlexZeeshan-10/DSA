#include <iostream>

class Node{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
        : data(data), next(next){}
};