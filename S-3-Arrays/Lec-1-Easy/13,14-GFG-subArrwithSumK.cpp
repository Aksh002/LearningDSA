//                                      SUBARRAY WITH SUM K


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // For NEGATIVE + POSITIVE nums 
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        unordered_map<long long,int> preSumMap;
        long long sum=0;
        int len=0;
        for (int i=0;i<arr.size();i++){
            sum+=arr[i];
            if (sum==k){
                len=i+1;
            }
            if (preSumMap.find(sum-k) !=preSumMap.end()){
                len=max(len,i-preSumMap[sum-k]);
            }
            
            //preSumMap.insert({sum,i});
            if (preSumMap.find(sum)==preSumMap.end()){          // For edge case containing 0
                preSumMap[sum]=i;
            }
        }
        return len;
    }
    // For POSITIVE nums only               
    // But BEST TC-
    // int lenOfLongestSubarr(vector<int>& arr, int k) {
    //     int left = 0, right = 0;
    //     long long sum = arr[0];
    //     int len = 0;
    //     int n = arr.size();
    
    //     while (right < n) {
    //         // Shrink the window if the sum exceeds k
    //         while (left <= right && sum > k) {
    //             sum -= arr[left];
    //             left++;
    //         }
    
    //         // Check if the current window has sum equal to k
    //         if (sum == k) {
    //             len = max(len, right - left + 1);
    //         }
    
    //         // Expand the window
    //         right++;
    //         if (right < n) {
    //             sum += arr[right];
    //         }
    //     }
    
    //     return len;
    //}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends