#include <bits/stdc++.h>
using namespace std;

void explainpair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    cout << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second;

    cout << endl;

    // array of pairs
    int i = 0, n = 3;
    pair<int,int> arr[] = {{1,2}, {3,4}, {5,6}};
    do
    {
        cout << arr[i].first << " " << arr[i].second   << "\n" ;
        i += 1;
    } while (i<n);
    
}

// void explainvector()
// {
//     vector<int> v;

//     v.push_back(1);
//     v.emplace_back(2);

//     vector<pair<int, int>> vec;

//     vec.push_back({1, 2});
//     vec.emplace_back(1, 2);

//     vector<int> v(5, 100);

//     vector<int> v(5);

//     vector<int> v1(5, 20);
//     vector<int> _v2(v1);

//     for (auto it = v1.begin(); it != v1.end(); it++)
//     {
//         cout << *(it) << " ";
//     }
//     cout << endl;
// }

void explainlist(){
    list <int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    
    ls.push_front(5);
    ls.emplace_front(2); 
}

void explainstack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;

    stack<int> st1;
    st1 = st;
    cout << st1.top() << endl;
}

void explainqueue()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5;

    cout << q.back() << endl; // prints 9
    // q is {1,2,9}

    cout << q.front() << endl;
    q.pop();                   // {2,9}
    cout << q.front() << endl; // prints 2
    // size swap same as stack
}

void explainPQ()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);
    cout << pq.top() << endl; // prints 10
    pq.pop();
    cout << pq.top() << endl; // prints 8

    priority_queue<int, vector<int>, greater<int>>
                    minheap;
    minheap.push(5);
    minheap.push(2);
    minheap.push(8);
    minheap.emplace(10);
    cout << "Min-heap top: " << minheap.top() << endl; // prints 2
}

void explainset()
{
   set<int>st;
   st.insert(1);
   st.emplace(2);
   st.insert(2);
   st.insert(4);
   st.insert(3);

   auto it = st.find(3);
   it = st.find(6);

   st.erase(5);
   
   int cnt = st.count(1);
   it = st.find(3);

   auto it1 = st.find(2);
   auto it2 = st.find(4);
   st.erase(it1, it2);

   auto it3 = st.lower_bound(2);
   auto it4 = st.upper_bound(3);
}

void explainMultiset()
{
    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.erase(1);

    int cnt = ms.count(1);
    ms.erase(ms.find(1));
    ms.erase(ms.find(1), next(ms.find(1), 2));

}

void explainMap(){

    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;
    
    mpp[1] = 2;
    mpp.insert({3, 2});
    
    for(auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
    
}

int main()
{
    explainMultiset();
    return 0;
}
