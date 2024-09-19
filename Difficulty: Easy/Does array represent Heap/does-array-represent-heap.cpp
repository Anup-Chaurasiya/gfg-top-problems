//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        
        for(int i=0;i<n;i++){
            int left = i * 2 +1;
            int right= i * 2 +2;
            
            if(left<n && arr[left]>arr[i]){
                return false;
            }
            if(right<n && arr[right]>arr[i]){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends