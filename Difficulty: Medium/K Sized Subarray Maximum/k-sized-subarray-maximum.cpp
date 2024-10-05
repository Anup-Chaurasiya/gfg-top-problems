//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
    vector<int>ans;
    deque<int>q;
    for(int i=0;i<k-1;i++){
        if(q.empty()){
            q.push_back(i);
        }
        else{
            while (!q.empty() && arr[i] > arr[q.back()]) {
              q.pop_back();
            }
            q.push_back(i);
        }
    }
    int n=arr.size();
    for(int i=k-1;i<n;i++){
        while(!q.empty() && arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);

        if(q.front()<=i-k){
            q.pop_front();
        }
        ans.push_back(arr[q.front()]);
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends