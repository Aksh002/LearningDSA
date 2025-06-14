#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int i=low;
    int j=high;
    int pivot=low;
    while (i<j){
        while (arr[i]<=arr[pivot] && i<=high-1){
            i++;
        }
        while (arr[j]>arr[pivot] && j>=low+1){
            j-- ;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[pivot]);
    return j;
}

void qS(vector<int> &arr,int low,int high){
    if (low<high){
        int partition_index= partition(arr,low,high);

        qS(arr,low,partition_index-1);

        qS(arr,partition_index+1,high);

    }
}



vector<int> quick_sort(vector<int>arr){
    qS(arr,0,arr.size()-1);
    return arr; 
}

int main(){
    vector<int>v=quick_sort({1,3,2,4,7,9,5,6});
    for (int i:v){
        cout << i << " ";
    }
    return 0;
}