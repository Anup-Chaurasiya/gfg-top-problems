//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        int n = array2.size();
        int m = array1.size();
        
        // Ensure array1 is the smaller array
        if (m > n) {
            return MedianOfArrays(array2, array1);
        }
        
        int start = 0, end = m;
        
        while (start <= end) {
            int i1 = start + (end - start) / 2;
            int i2 = (m + n + 1) / 2 - i1;
            
            int min1 = (i1 == m) ? INT_MAX : array1[i1];
            int max1 = (i1 == 0) ? INT_MIN : array1[i1 - 1];
            
            int min2 = (i2 == n) ? INT_MAX : array2[i2];
            int max2 = (i2 == 0) ? INT_MIN : array2[i2 - 1];
            
            if (max1 <= min2 && max2 <= min1) {
                if ((m + n) % 2 == 0) {
                    return (double)(max(max1, max2) + min(min1, min2)) / 2.0;
                } else {
                    return (double)max(max1, max2);
                }
            } else if (max1 > min2) {
                end = i1 - 1;
            } else {
                start = i1 + 1;
            }
        }
        
        // If inputs are invalid
        return -1.0;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends