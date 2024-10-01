//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
    int n=arr.size();
    int leftMax=0;
    int rightMax=0;
    long long ans=0;
    int index=0;
    int maxHeight=INT_MIN;

    for(int i=0;i<n;i++){
        if(maxHeight < arr[i]){
            maxHeight = arr[i];
            index=i;
        }
    }
// leftMax

    for(int i=0;i<index;i++){
        if(leftMax > arr[i]){
            ans += leftMax - arr[i];
        }
        else {
            leftMax = arr[i];
        }
    }
// rightMax
    for(int i=n-1;i>=index;i--){
        if(rightMax > arr[i]){
            ans += rightMax - arr[i];
        }
        else {
            rightMax = arr[i];
        }
    }


    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends