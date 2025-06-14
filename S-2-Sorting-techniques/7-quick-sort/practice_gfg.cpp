// Quick Sort W/O using nested WHILE loop

// SOLUTION LINK:-
// https://leetcode.com/problems/sort-an-array/solutions/1401412/c-clean-code-solution-fastest-all-15-sorting-methods-detailed

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if (low>=high){
            return;
        }
        int pivot=partition(arr,low,high);
        
        quickSort(arr,low,pivot-1);
        
        quickSort(arr,pivot+1,high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot=low;
        int left=low+1;
        int right=high;
        while (left<=right){
            if (arr[left]<arr[pivot]){
                left++;
            }
            else if (arr[right]>arr[pivot]){
                right--;
            }
            else{
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
        swap(arr[pivot],arr[right]);
        
        return right;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends
// (TLE) [T(n) = O(n^2)]


//  Randomised pivot method:- 
int partitionArray(vector<int> &nums, int low, int high) {
	if (low >= high) return -1;
	int pivot = low, l = pivot + 1, r = high;
	while (l <= r)
		if (nums[l] < nums[pivot]) l++;
		else if (nums[r] >= nums[pivot]) r--;
		else swap(nums[l], nums[r]);
	swap(nums[pivot], nums[r]);
	return r;
}

void quickSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	swap(nums[low + rand() % (high - low + 1)], nums[low]);
	int pivot = partitionArray(nums, low, high);
	quickSort(nums, low, pivot);
	quickSort(nums, pivot + 1, high);
}
// (TLE) [T(n) = O(n * lgn) on avg. but O(n^2) in worst case]