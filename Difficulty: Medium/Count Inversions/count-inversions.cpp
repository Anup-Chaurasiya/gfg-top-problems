//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    void merge(vector<int>& arr, int s, int e, int &count) {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        // Temporary arrays
        vector<int> first(len1), second(len2);

        // Copy 1st part
        for (int i = 0; i < len1; i++) {
            first[i] = arr[s + i];
        }

        // Copy 2nd part
        for (int i = 0; i < len2; i++) {
            second[i] = arr[mid + 1 + i];
        }

        // Merging
        int index1 = 0, index2 = 0, k = s;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] <= second[index2]) {
                arr[k++] = first[index1++];
            } else {
                count += len1 - index1; // Count inversions
                arr[k++] = second[index2++];
            }
        }

        // Copy remaining elements
        while (index1 < len1) {
            arr[k++] = first[index1++];
        }
        while (index2 < len2) {
            arr[k++] = second[index2++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r, int &count) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        // Sort left and right halves
        mergeSort(arr, l, mid, count);
        mergeSort(arr, mid + 1, r, count);

        // Merge sorted halves
        merge(arr, l, r, count);
    }

public:
    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        int count = 0;
        mergeSort(arr, 0, arr.size() - 1, count);
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends