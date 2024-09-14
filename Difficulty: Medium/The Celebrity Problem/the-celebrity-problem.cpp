//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int>s;
        int val=0;
        int size=mat.size();
       for(int i=0;i<size;i++){
           s.push(i);
       }
        
        while(s.size()>1){
            int top1=s.top();
            s.pop();
            int top2=s.top();
            s.pop();
            if(mat[top2][top1]==0){
                s.push(top2);
            }
            else{
                s.push(top1);
            }
        }
        
       int candidate = s.top();
        
        // Step 2: Verify if the candidate is actually a celebrity
        for (int i = 0; i < size; ++i) {
            if (i != candidate) {
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1; // candidate knows someone or not known by someone
                }
            }
        }
        
        return candidate;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends