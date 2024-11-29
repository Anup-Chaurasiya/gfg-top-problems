//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    void merge(vector<int>& arr, int s, int e){
        
        int mid = s+(e-s)/2;
        
        int len1 = mid-s+1;
        int len2 = e-mid;
        
        int* first = new int[len1];
        int* second = new int[len2];
        
        // copy 1st part
        int k = s;
        for(int i=0;i<len1;i++){
            first[i] = arr[k++];
        }
        
        // copy 2st part
        k = mid+1;
        for(int i=0;i<len2;i++){
            second[i] = arr[k++];
        }
        
        int index1=0;
        int index2=0;
        int start = s;
        
        while(index1 < len1 && index2 < len2){
            if(first[index1]<second[index2]){
                arr[start++] = first[index1++];
            }
            else{
                arr[start++] = second[index2++];
            }
        }
        
         while(index1 < len1){
             arr[start++] = first[index1++];
         }
         while(index2 < len2){
             arr[start++] = second[index2++];
         }
         
         delete []first;
         delete []second;
        
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        
        if(l>=r){
            return ;
        }
        
        int mid = l+(r-l)/2;
        
        // left sort
        mergeSort(arr,l,mid);
        
        // right sort
        mergeSort(arr,mid+1,r);
        
        // merge srted array
        merge(arr,l,r);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends