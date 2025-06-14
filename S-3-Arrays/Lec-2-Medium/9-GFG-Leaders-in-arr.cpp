#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        // Code here
        // vector<int> ans;
        // int i,j;
        //  for (i = arr.size()-1;i>=0;i--){
        //      for (j=i;j<arr.size();j++){
        //          if (arr[j]>arr[i]){
        //              break;
        //          }
        //      }
        //      if (j == arr.size()){
        //          ans.push_back(arr[i]);
        //      }
        //  }
        // reverse(ans.begin(),ans.end());
        // return ans;

        vector<int> ans;
        int i;
        int largest = arr.size() - 1;
        for (i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] >= arr[largest])
            {
                ans.push_back(arr[i]);
                largest = i;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};