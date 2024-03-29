//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
            for(int i=0;i<=n;i++){
                dp[0][i]= i*price[0];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<=n;j++){
                     int not_pick=dp[i-1][j];
                int pick=0;
                int rod_length=i+1;
                if(rod_length<=j){
                    pick= price[i]+dp[i][j-rod_length];
                }
                dp[i][j]=max(pick,not_pick);
                }
            }
            return dp[n-1][n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends