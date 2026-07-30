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


Node *convertToDoublyLL(std::vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    
    Node *head = convertToDoublyLL(arr);

    return 0;
}