//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(int k, vector<int>& array1, vector<int>& array2) {
        
        
        int m = array1.size();
        int n = array2.size();
        
        // Ensure array1 is the smaller array
        if (m > n) {
            return kthElement(k, array2, array1);
        }
        
        int start = max(0, k - n);
        int end = min(k, m);
        
        while (start <= end) {
            int i1 = start + (end - start) / 2;
            int i2 = k - i1;
            
            if (i2 < 0) {
                end = i1 - 1;
                continue;
            } else if (i2 > n) {
                start = i1 + 1;
                continue;
            }
            
            int min1 = (i1 == m) ? INT_MAX : array1[i1];
            int max1 = (i1 == 0) ? INT_MIN : array1[i1 - 1];
            
            int min2 = (i2 == n) ? INT_MAX : array2[i2];
            int max2 = (i2 == 0) ? INT_MIN : array2[i2 - 1];
            
            if (max1 <= min2 && max2 <= min1) {
                return max(max1, max2);
            } else if (max1 > min2) {
                end = i1 - 1;
            } else {
                start = i1 + 1;
            }
        }
       
        
        // int m = array1.size();
        // int n = array2.size();
        
        // // Ensure array1 is the smaller array
        // if (m > n) {
        //     return kthElement(k,array2, array1);
        // }
        
        // int start = max(0,k-n);
        // int end = min(k,m);
        
        // while (start <= end) {
        //     int i1 = start + (end - start) / 2;
        //     int i2 = (m + n + 1) / 2 - i1;
            
        //     int min1 = (i1 == m) ? INT_MAX : array1[i1];
        //     int max1 = (i1 == 0) ? INT_MIN : array1[i1 - 1];
            
        //     int min2 = (i2 == n) ? INT_MAX : array2[i2];
        //     int max2 = (i2 == 0) ? INT_MIN : array2[i2 - 1];
            
        //     if (max1 <= min2 && max2 <= min1) {
                
        //         return max(max1,max2);
            
        //     } else if (max1 > min2) {
        //         end = i1 - 1;
        //     } else {
        //         start = i1 + 1;
        //     }
        // }
        
        // If inputs are invalid
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends