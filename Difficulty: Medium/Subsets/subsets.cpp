//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(arr, 0, current, result);
        sort(result.begin(),result.end());
        return result;
    }

private:
    void generateSubsets(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
        if (index == arr.size()) {
            result.push_back(current);
            return;
        }
        

        // Recur to include the next element
        generateSubsets(arr, index + 1, current, result);
        current.push_back(arr[index]);
        generateSubsets(arr, index + 1, current, result);
        
        // Backtrack to exclude the current element and continue
        current.pop_back();
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends