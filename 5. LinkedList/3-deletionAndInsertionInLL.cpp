#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    int head = convertArrToLL(arr);
}