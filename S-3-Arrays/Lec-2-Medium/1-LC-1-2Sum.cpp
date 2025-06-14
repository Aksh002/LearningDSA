#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute method:-
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {};
    // }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }
            else {
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};        
    }
};



//                                          Yes No variation
bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int sum=0;
        while (i<j){
            sum=arr[i]+arr[j];
            if (sum==target){
                return true;
            }
            else if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
        }
        return false;
    }