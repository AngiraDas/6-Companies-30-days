//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int l=0;
        int r=n-1;
        int ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]<k){
                l=m+1;
            }
            else if( arr[m]>k){
                r=m-1;
            }
            else {
                ans=m;
                break;
            }
        }
        if(ans==-1){
            return -1;
        }
        else{
            return ans;
        }
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends