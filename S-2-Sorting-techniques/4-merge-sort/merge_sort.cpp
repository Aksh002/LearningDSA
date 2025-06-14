#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if (arr[left]<arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }

    for (int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mS(vector<int> &arr,int low,int high){
    if (low>=high)
        return;
    int mid=(high+low)/2;

    mS(arr,low,mid);

    mS(arr,mid+1,high);

    merge(arr,low,mid,high);
}

void mergeSort(vector <int>&arr,int n){
    mS(arr,0,n-1);
}

int main(){
    vector<int>v={3,1,2,4,1,5,6,2,4};
    mergeSort(v,9);

    cout << "Sorted Array:" << endl;
    for(int i:v){
        cout << i << " ";
    }
    return 0;
}