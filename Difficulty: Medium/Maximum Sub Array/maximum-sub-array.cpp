//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int nums[]) {
        int maxSum = 0;
        int maxLen = 0;
        int bestStart = -1;
        int sum = 0;
        int tempStart = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                sum = 0; // Reset sum for negative number
                tempStart = i + 1; // Set new starting point for the next potential subarray
            } else {
                sum += nums[i]; // Add to current sum

                // Check for maximum sum and length
                int currentLen = i - tempStart + 1;
                if (sum > maxSum || (sum == maxSum && currentLen > maxLen)) {
                    maxSum = sum; 
                    maxLen = currentLen;
                    bestStart = tempStart; // Update best starting index
                }
            }
        }
        
        if (bestStart == -1) return {-1}; // If no valid subarray found

        for (int i = bestStart; i < bestStart + maxLen; i++) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends