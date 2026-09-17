#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> findPair(Node *head, int sum)
{
    std::vector<std::vector<int>> ans;
    Node *temp1 = head;
    while (temp1)
    {
        Node *temp2 = temp1->next;
        while (temp2 && (temp1->data + temp2->data) <= sum)
        {
            if (temp1->data + temp2->data == sum)
                ans.push_back({temp1->data, temp2->data});

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

std::vector<std::vector<int>> findPairBetter(Node *head, int sum)
{
    std::vector<std::vector<int>> ans;
    Node *temp = head;
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    while (temp->data < tail->data)
    {
        if ((temp->data + tail->data) == sum)
        {
            ans.push_back({temp->data, tail->data});
            temp = temp->next;
            tail = tail->prev;
        }
        else if ((temp->data + tail->data) < sum)
            temp = temp->next;

        else
            tail = tail->prev;
    }
    return ans;
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
            temp->prev = tail;
            tail = temp;
        }
    }
    Node *temp = head;
    std::cout << "nullptr <->";
    while (temp)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;

    int sum;
    std::cin >> sum;

    std::vector<std::vector<int>> ans = findPairBetter(head, sum);

    for (size_t i = 0; i < ans.size(); ++i)
    {
        for (size_t j = 0; j < ans[i].size(); ++j)
        {
            std::cout << ans[i][j] << " ";
        }

        std::cout << '\n';
    }

    return 0;
}