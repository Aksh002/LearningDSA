//                                                          ALGORITHMS
//                                                          using stl
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void explainExtra(){
    int a[5];
    vector<int>v;

    sort(a,a+3);                    // [strart iterator,end iterator)
    sort(v.begin(),v.end());
    sort(a+1,a+5);

    // TO sort in a custom way:-
    pair<int,int>a[]={{1,2},{2,1},{4,1}};
    // sort it acc to the secound element, if sec element is same then go for first element, but sort it discendingly then
    bool comp(pair<int,int>p1,pair<int,int>p2){
        if (p1.second<p2.second)
            return true;
        else if (p1.second>p2.second)
            return false;
        else{
            if (p1.first>p2.first)
                return true;
            else 
                return false;
        }
    }
    sort(a,a+5,comp);




    //                                  _builtin_popcount
    int cnt=__builtin_popcount(7);               // return no. of high bits in a binary representation of passed no.

    long long num=1234546543234435;
    int cnt=__builtin_popcountll(num);

    string s="132";
    sort(s.begin(),s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));

    int maxi=*max_element(a,a+5);
}