#include <iostream>
#include <vector>
#include <algorithm>
class Node
{
public:
    int val;
    Node *prev;
    Node *next;

public:
    Node(Node *prev1, int val1, Node *next1)
        : prev(prev1), val(val1), next(next1) {}

    Node(int val1)
        : prev(nullptr), val(val1), next(nullptr) {}
};

Node *mergeTwoListBrute(Node *list1, Node *list2){
    if(list1 == nullptr)
            return list2;
        
        if(list2 == nullptr)
            return list1;
        
        std::vector <int> store;
        Node *temp = list1;
        while(temp){
            store.push_back(temp->val);
            temp = temp->next;
        }

        temp = list2;
        while(temp){
            store.push_back(temp->val);
            temp = temp->next;
        }

        std::sort(store.begin(), store.end());
        Node *newHead = new Node(store[0]);
        temp = newHead;
        for(int i = 1; i<store.size(); ++i){
            Node *mover = new Node(store[i]);
            temp->next = mover;
            temp = temp->next;
        }
        return newHead;
}

int main()
{
    int n1;
    std::cin >> n1;

    Node *head1 = nullptr;
    Node *tail1 = nullptr;

    while (n1--)
    {
        int x;
        std::cin >> x;
        Node *temp = new Node(x);
        if (head1 == nullptr)
        {
            head1 = temp;
            tail1 = temp;
        }
        else
        {
            tail1->next = temp;
            temp->prev = tail1;
            tail1 = temp;
        }
    }

    int n2;
    std::cin >> n2;

    Node *head2 = nullptr;
    Node *tail2 = nullptr;

    while (n2--)
    {
        int x;
        std::cin >> x;
        Node *temp = new Node(x);
        if (head2 == nullptr)
        {
            head2 = temp;
            tail2 = temp;
        }
        else
        {
            tail2->next = temp;
            temp->prev = tail2;
            tail2 = temp;
        }
    }

    Node *head = mergeTwoListBrute(head1, head2);

    Node *temp = head;
    std::cout << "nullptr <-> ";
    while (temp)
    {
        std::cout << temp->val << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

}