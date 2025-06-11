//                                                      HASHING
#include <bits/stdc++.h>
using namespace std;

/*
//                              Example
int main(){
    int n;
    printf("enter size:");
    cin >> n;
    int a[n];
    printf("\n Enter values\n");
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    // Pre-Compute
    int hash[13]={0};                    // lets say 12 could be the max no. magnitude, so we make hash array of size 13
    for (int i=0;i<n;i++){
        hash[a[i]]+=1;
    }

    int q;
    printf("Enter no of querry");
    cin >> q;
    while(q--){
        int num;
        printf("Enter query:");
        cin >> num;
        // fetch
        cout << hash[num] << endl;
    }
    return 0;
}


//                                                      Charachter Hashing
int main(){
    string s;
    printf("enter string:");
    cin >> s;

    // Pre-Compute
    int hash[26]={0};                   
    for (int i=0;i<s.size();i++){
        hash[s[i]-'a']++;                        // Passed chaachter is auto converted to int value which is its ASCII value 
    }

    int q;
    printf("Enter no of querry");
    cin >> q;
    while(q--){
        char c;
        printf("Enter query:");
        cin >> c;
        // fetch
        cout << hash[c-'a'] << endl;            // 'A' if uppercase
    }
    return 0;
}

// Another way:-
// THis will a bigger array , but doesnt matter
// Prefer prev one always
int main(){
    string s;
    printf("enter string:");
    cin >> s;

    // Pre-Compute
    int hash[256]={0};                   
    for (int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    int q;
    printf("Enter no of querry");
    cin >> q;
    while(q--){
        char c;
        printf("Enter query:");
        cin >> c;
        // fetch
        cout << hash[c] << endl;            // 'A' if uppercase
    }
    return 0;
}

*/

//                                  Maps as Hashing array
int main(){
    int n;
    printf("enter size:");
    cin >> n;
    int a[n];
    printf("\n Enter values\n");
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    // Pre-Compute
    map<int,int>mpp;
    for (int i=0;i<n;i++){
        mpp[a[i]]+=1;
    }

    // Iterating over map
    // for(auto it:mpp){
    //     cout << it.first << "->" << it.second << endl;
    // }

    int q;
    printf("Enter no of querry");
    cin >> q;
    while(q--){
        int num;
        printf("Enter query:");
        cin >> num;
        // fetch
        cout << mpp[num] << endl;
    }
    return 0;
}