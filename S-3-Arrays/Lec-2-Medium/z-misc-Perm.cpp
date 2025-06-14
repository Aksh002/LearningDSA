#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //vector<bool> mp(nums.size(), false);
        vector<vector<int>> ans;
        //vector <int> temp;
        //perm(mp,nums,temp,ans);
        int ptr=0;
        perm(nums,ans,0);
        return ans;
    }
    // void perm(vector<bool> &mp,vector< int>& nums,vector<int>&temp,vector<vector<int>> &ans){
        
    //     if (temp.size()==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for (int i=0;i<nums.size();i++){
    //         if (!mp[i]){
    //             mp[i]=true;
    //             temp.push_back(nums[i]);
    //             perm(mp,nums,temp,ans);
    //             temp.pop_back();
    //             mp[i]=false;
    //         }
    //     }
    // }
    void perm(vector< int>& nums,vector<vector<int>> &ans,int ptr){
        if (ptr==nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i=ptr;i<nums.size();i++){
            swap(nums[ptr],nums[i]);
            perm(nums,ans,ptr+1);
            swap(nums[ptr],nums[i]);
        }
    }
};
