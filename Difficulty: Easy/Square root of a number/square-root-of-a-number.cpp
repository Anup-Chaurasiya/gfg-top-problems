//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long long int start = 1, end = x, ans = -1;
        
        while (start <= end) {
            long long int mid = start + (end - start) / 2;
            
            // Avoid overflow by dividing x by mid instead of multiplying mid*mid
            if (mid <= x / mid) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends