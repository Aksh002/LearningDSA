//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*

Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

*/
//Intiution:- Avariation of binary search

//https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for (int i = 0; i < mat.size(); i++) {
        if (bs(mat[i], 0, mat[i].size() - 1, x)) {
            return true; // Exit early if the target is found
        }
    }
    return false;
    }
    bool bs(vector<int>&arr,int low,int high,int target){
        // bool found=false;
        int mid = (high+low)/2;
        
        if (low>high){
            return false;
        }
        
        if (arr[mid]==target){
            return true;
        }
        else if (target<arr[mid]){
            return bs(arr,low,mid-1,target);
        }
        else if(target>arr[mid]){
            return bs(arr,mid+1,high,target);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends