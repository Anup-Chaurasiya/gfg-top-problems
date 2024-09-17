//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLen(string s) {
        stack<int> st;
        st.push(-1); // Initialize with -1 to handle the base case where the valid substring starts from index 0
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(i); // Push the index of the opening bracket
            } else {
                if (!st.empty()) {
                    st.pop(); // Pop the matching opening bracket index
                    if (!st.empty()) {
                        maxLen = max(maxLen, i - st.top()); // Calculate the length of the current valid substring
                    } else {
                        st.push(i); // Update base index
                    }
                }
            }
        }
        
        return maxLen;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends