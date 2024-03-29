//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int i,vector<int>&height,vector<int>&dp){
      if(i==0){
          return 0;
      }
      if(dp[i]!=-1){
          return dp[i];
      }
      int r=INT_MAX;
      int l=f(i-1,height,dp)+abs(height[i]-height[i-1]);
      if(i>1){
          r=f(i-2,height,dp)+abs(height[i]-height[i-2]);
      }
      return dp[i]=min(l,r);
      
  }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return f(n-1,height,dp);
        // Code here
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
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends