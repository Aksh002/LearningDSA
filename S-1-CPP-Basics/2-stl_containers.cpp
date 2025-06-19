//                                              Containers
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//                                              Pairs
void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> pa = {1, {2, 3}};
    cout << p.first << " " << pa.second.first << " " << pa.second.second;

    pair<int, int> par[] = {{1, 2}, {3, 4}, {3, 5}};
    cout << par[2].second;
}

//                                              Vectors
// Its a type of a container that stores data just like array but its size is dynamic, not predefined

void explainVector()
{
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vp;

    v.push_back({1, 2});
    v.emplace_back(1, 2); // in emplace_back we can add pairs directly

    vector<int> v(5, 100); // (size,value)     // {100,100,100,100,100}

    vector<int> v(5); // (size)

    vector<int> v1(5, 20);
    vector<int> v2(v1); // Copying

    vector<int>::iterator it = v.begin(); // it Points to 0th index,.begin() provides address of it

    it++;
    cout << *(it) << " "; // prints element at index 1

    vector<int>::iterator it = v.end();    // poitns at the pos after the last index, .end() provides (address of nth element+1)
    vector<int>::iterator it = v.rend();   // points to the pos before the first index, .rend() provides (address of 0th element-1)
    vector<int>::iterator it = v.rbegin(); // points to nth index, .end() provides address of nth index

    cout << v[0] << " " << v.at(0);
    cout << v.back(); // return last element

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // this much typing is tooo much
    for (auto it : v.begin(); it !-v.end(); it++)
    {
        cout << *(it) << " ";
    }
    for (auto it : v)
    {
        cout << it << " ";
    }

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2, v.begin() + 4); // [start,end)

    cout << v.size();

    // INsert Fxn
    vector<int> v(5, 100);
    v.insert(v.begin(), 300);    // (pos,value)
    v.insert(v.begin(), 2, 300); // (pos,quantity,value)

    vector<int> copy(5, 10);
    v.insert(v.begin(), copy.begin(), copy.end()); // copy copied to v

    v.pop_back();

    v.clear();

    v1.swap(v2);

    cout << v.empty(); // if_empty:True, else:False
}

void explainList()
{
    list<int> ls;

    ls.push_back(1);
    ls.emplace_back(2);

    ls.push_front(8);
    ls.emplace_front(5); // Better then using insert in vector

    // begin,end,rbegin,erend,insert,clear,swap,size same as vector
}

void explainDeque()
{
    deque<int> dq;

    // push_back,emplace_back,push_front,emplace_front,begin,end,rbegin,erend,insert,clear,swap,size same as list

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
}

void explainStack()
{
    stack<int> st;

    st.push(2);
    st.emplace(4);
    st.push(6);
    //{2,4,6}

    cout << st.top(); // 6

    st.pop();
    //{2,4}

    cout << st.top(); // 4

    cout << st.size();

    st.empty();
}

void explainQueue()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.emplace(4);

    //{1,2,4}
    cout << q.back();  // 4
    cout << q.front(); // 1

    q.pop();
    // {2,4}

    // Rest same as stack
}

void explainPriority_queue()
{
    priority_queue<int> pq;

    // MAX Heap :- Highest one on top
    pq.push(1);
    pq.push(5);
    pq.emplace(2);
    //{5,2,1}

    cout << pq.top(); // 5
    pq.pop();
    // {2,1}

    cout << pq.top(); // 2

    // MIN Heap:- Leaast one on top
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(5);
    pq.emplace(2);
    //{1,2,5}

    cout << pq.top(); // 1
}

void explainSet()
{
    //  SORTED
    //  UNIQUE
    set<int> st;

    //
    st.insert(1);  //{1}
    st.emplace(3); //{1,3}
    st.insert(1);  //{1,3}
    st.insert(3);  //{1,3}
    st.insert(2);  //{1,2,3}

    //
    auto it = st.find(3); // retuns iterator that points to 3
    auto it = st.find(6); // As 6 is not there, it will return st.end(), means an iterator that points right after the end

    //
    st.erase(2);

    //
    int cnt = st.count(2);

    //
    auto it = st.find(4);
    st.erase(it); // Can also pass the itterator

    //
    auto it1 = st.find(1);
    auto it2 = st.find(2);
    st.erase(it1, it2); // [start,end)

    // lower_bound(), upper_bound() fxns the same way like in Vector
    auto it = st.lower_bound(2);

    auto it = st.lower_bound(3);
}

void explainBinary_search()
{

    vector<int> v = {1, 2, 3, 4, 6};

    bool found = binary_search(v.begin(), v.end(), 5); // Return a boolean term , true if found ofc
}

void explainLower_Bound()
{
    vector<int> v = {1, 2, 3, 6, 9};
    auto it = lower_bound(v.begin(), v.end(), 3);  // Return an iterator that points to the position where target is found
    auto it = lower_bound(v.begin(), v.end(), 7);  // If the no. is not find in the array, it returns a pointer that points towards the next gretest no. avialable that is 9
    auto it = lower_bound(v.begin(), v.end(), 10); // If there is no one greater then the unfound no. in the array, it points afyter the end of the array
}

void explainUpper_Bound()
{
    vector<int> v = {1, 2, 3, 6, 9};
    auto it = upper_bound(v.begin(), v.end(), 3);  // Return an iterator that points to the position where number just greater then target is found
    auto it = upper_bound(v.begin(), v.end(), 7);  // If the no. is not find in the array, it returns a pointer that points towards the next gretest no. avialable that is 9
    auto it = upper_bound(v.begin(), v.end(), 10); // If there is no one greater then the unfound no. in the array, it points afyter the end of the array
}

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1,1,1}

    ms.erase(1); // All 1's erased

    int cnt = ms.count(1);

    ms.erase(ms.find(1)); // Erase only first occurance of 1
    ms.erase(ms.find(1), ms.find(1) + 2);
}

void explainUSet()
{
    unordered_set<int> ust;
    // lower_bound and upper_bound fxn does not work here
    // Rest all fxns are same as before
    // it does not store in any perticular order , it has a better time complexity then set in most cases
}

void explainMap()
{

    map<int, int> mp;
    map<int, pair<int, int>> mp;
    map<pair<int, int>, int> mp1;

    mp[1] = 2; // Assign value of 2 to the key 1
    mp.emplace({3, 1});
    mp.insert({2, 4});

    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }

    mp1[{2, 3}] = 10;

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[1]; // 2

    auto it = mp.find(1); // adress of 2
    cout << it->second;
    auto it = mp.find(5); // returns mp.end() as 5 not pressent

    int presentOrNot = mp.count(2); // Returns 1 if found the key, else 0.

    auto it = mp.lower_bound(2);
    auto it = mp.lower_bound(3);

    // Time complexity: 0(logn)
}

void explainMultimap()
{
    // Everythoing as map
    // Sorted order
    // Differenes:-
    //              can store multiple keys
}

void explainUnorderedMap()
{
    // Same as map
    // Difference:-
    //              NOt in sorted order
    //              time complexity:- 0(1)
}
