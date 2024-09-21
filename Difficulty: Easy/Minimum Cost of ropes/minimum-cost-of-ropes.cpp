//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        int size=arr.size();
        long long ans=0;
        
        priority_queue<long long,vector<long long>,greater<long long>>q;
        
        for(auto i : arr){
            q.push(i);
        }
        
        while(q.size()!=1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            ans +=a+b;
            q.push(a+b);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends