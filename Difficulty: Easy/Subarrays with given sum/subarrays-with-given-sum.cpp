//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subArraySum(vector<int>& arr, int k) {
       unordered_map<int, int> mp;
    int sum = 0;
    int count = 0;

    mp[0] = 1; // To handle the case where a subarray from the start has sum k

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Compute cumulative sum

        // Check if sum - k exists in the map, if it does, add its frequency to count
        if (mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }

        // Update the frequency of the current sum
        mp[sum]++;
    }

    return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.subArraySum(arr, k);
        cout << '\n';
    }
    return 0;
}
// } Driver Code Ends