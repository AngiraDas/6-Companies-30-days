//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        int c=0;
        int n=A.size();
        int s=accumulate(A.begin(),A.end(),c);
        int t=s-target;
       
        if(t%2!=0||t<0){
            return 0;
        }
        else{
            int newtarget=t/2;
            vector<vector<int>>dp(n,vector<int>(newtarget+1,0));
            for(int i=0;i<n;i++){
                if(A[i]==0){
                    dp[i][0]=2;
                }
                else{
                dp[i][0]=1;
                }
            }
           if(A[0]<=newtarget&&A[0]!=0){
               dp[0][A[0]]=1;
           }
            for(int i=1;i<n;i++){
                for(int j=0;j<=newtarget;j++){
                    int not_pick=dp[i-1][j];
                    int pick=0;
                    if(A[i]<=j){
                        pick=dp[i-1][j-A[i]];
                    }
                    dp[i][j]=pick+not_pick;
                }
            }
            return dp[n-1][newtarget];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends