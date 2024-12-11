//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        unordered_map<char,int>mpp;
        
         char maxChar = s[0];
        int maxFreq = 0;

        for (char c : s) {
            mpp[c]++;
            
            if (mpp[c] > maxFreq || (mpp[c] == maxFreq && c < maxChar)) {
                maxFreq = mpp[c];
                maxChar = c;
            }
        }
        
        return maxChar;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends