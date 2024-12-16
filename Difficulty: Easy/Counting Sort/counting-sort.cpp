//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
       int n = arr.size();
       unordered_map<char,int>mpp;
       
       int minValue = 'a'-'0';
       int maxValue = 'z'+ '0';
       for(char i : arr){
           mpp[i]++;
       }
       
       int index = 0;
       for(char i ='a';i<='z';i++){
           if(mpp.find(i) != mpp.end()){
               int count = mpp[i];
               while(count--){
                   arr[index++] = i ;
               }
           }
       }
       
       return arr;
       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends