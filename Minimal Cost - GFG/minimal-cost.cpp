//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(vector<int>height,int k,int i,vector<int>&dp,int n){
      
        
        dp[0]=0;
        for(int i=0;i<n;i++){
            int r=INT_MAX;
             
        for(int j=1;j<=k;j++){
           if(i-j>=0){
            int p=dp[i-j]+abs(height[i]-height[i-j]);
            r=min(p,r);
            dp[i]=r;
            }
        }
        }
        return dp[n-1];
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n+1,-1);
        return f(height,k,n,dp,n);
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends