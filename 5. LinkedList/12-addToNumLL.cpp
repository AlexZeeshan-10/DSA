#include <iostream>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
        : data(data), next(next) {}

    Node(int data)
        : data(data), next(nullptr) {}
};

Node *reverseNode(Node *curr){
    Node *prev = nullptr;
    while (curr)
    {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node *addOneBrute(Node *head){
    head = reverseNode(head);
    Node *temp = head;
    int carry = 1;

    while (temp)
    {
        temp->data += carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1){
        Node *newNode = new Node(1);
        head = reverseNode(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseNode(head);
    return head;
}

int main()
{
    int n;
    std::cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    while (n--)
    {
        int x;
        std::cin >> x;
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    head = addOneBrute(head);

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr";
}