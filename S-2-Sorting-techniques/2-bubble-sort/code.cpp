#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector <int> &a){
    int n=a.size();
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp; 
            }
        }
    }
}

// Optimised bubble sort( TC for best case be )
void optimisedBubbleSort(vector <int> &a){
    int n=a.size();
    for (int i=0;i<n-1;i++){
        int doneSwap=0;
        for (int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp; 
                doneSwap=1;
            }
        }

        if (doneSwap==0){
            break;
        }
    }
}