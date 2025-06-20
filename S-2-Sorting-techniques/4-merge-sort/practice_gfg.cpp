//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int mid= (l + r)/2;
        
        if (l >= r){
            return;
        }
        
        mergeSort(arr,l,mid);
        
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
    
    void merge(vector <int> &arr,int l,int mid,int r){
        vector <int> temp;
        int left=l,right=mid+1;
        
        while (left<=mid && right<=r){
            if (arr[left]<arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }   
        }
        
        while (left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends