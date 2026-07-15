#include <bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;

    
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0], nullptr);
    cout << y;
}