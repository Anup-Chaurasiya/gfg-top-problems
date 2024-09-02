//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    void findsubSet(vector<int> &arr,int index,int sum, int n,vector<int> &result){
        
        if(index>=n){
            result.push_back(sum);
            return ;
        }
        
         findsubSet(arr,index+1,sum,n,result);
         
         findsubSet(arr,index+1,sum + arr[index],n,result);
        
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>result;
        int index=0,sum=0;
       findsubSet(arr,index,sum,n,result);
       
       return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends