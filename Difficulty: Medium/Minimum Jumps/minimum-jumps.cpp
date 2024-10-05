//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& nums) {
        int jump=0;
        int maxIndex=0;
        int currIndex=0;

        for(int i=0;i<nums.size()-1;i++){
            maxIndex = max( maxIndex , i + nums[i]);

            if(i==currIndex){
                jump++;
                currIndex=maxIndex;
                if(i>=currIndex){
                    return -1;
                }
            } 
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends