#include <bits/stdc++.h>
using namespace std;

void selec_sort(vector <int> &a){
    int n=a.size();
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int j=i;j<n;j++){
            if (a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}