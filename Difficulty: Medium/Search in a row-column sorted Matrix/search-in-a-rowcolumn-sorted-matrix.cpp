//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int search(vector<vector<int>> &mat, int N, int M, int X) {
        int row = 0;
        int col = M - 1;

        while (row < N && col >= 0) {
            if (mat[row][col] == X) {
                return 1; // Found X
            } else if (mat[row][col] > X) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }

        return 0; // X not found
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends