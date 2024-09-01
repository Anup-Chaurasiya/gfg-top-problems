//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(pair<double,Item> a,pair<double,Item> b){
    return a.first > b.first;
} 


class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        vector<pair<double,Item>>v;
        
        for(int i=0;i<n;i++){
            double perunitValue= (1.0*arr[i].value)/arr[i].weight;
            
            // pair<double,Item>v=make_pair(perunitValue,arr[i]);
            // v.push_back(v);
            
            // or
            
            v.push_back({perunitValue,{arr[i].value,arr[i].weight}});
        }
        
        double maxprofit=0;
        
        sort(v.begin(),v.end(),comp);
        
        for(int i=0;i<n;i++){
            
            // if upcoming weight is greater than the rest weight of container
            
            if(v[i].second.weight > w){
                 maxprofit += w * v[i].first;
                 w=0;
                 
            }
            // if upcoming weight is less than or equal to the container weight
            else{
                maxprofit +=v[i].second.value;
                w = w - v[i].second.weight ;
            }
        }
        
        return maxprofit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends