#include <iostream>
#include <vector>
class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
        : data(data1), next(next1) {}

    Node(int data1)
        : data(data1), next(nullptr) {}
};

Node *CreateLL(int x, int y){
    std::vector<int> arrx;
    while (x)
    {
        arrx.push_back(x%10);
        x /= 10;
    }
    std::vector<int> arry;
    while (y)
    {
        arry.push_back(y%10);
        y /= 10;
    }
    
}

int main(){
    int n1, n2;
    std::cin >> n1;
    std::cin >> n2;
    
}