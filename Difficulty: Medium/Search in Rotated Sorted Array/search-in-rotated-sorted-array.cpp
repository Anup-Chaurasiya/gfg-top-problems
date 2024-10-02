//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& nums, int target) {
        // complete the function here
        int start=0,end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }    
          else if(nums[mid]>=nums[0]){
                    if(nums[start]<=target&&nums[mid]>=target)
                        end=mid-1;
                    else
                        start=mid+1;
            }
            else if(nums[mid]<=target&&nums[end]>=target){
                            start=mid+1;
            }                
            else{
                end=mid-1;
            }
       
        }       

        return -1;  
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends