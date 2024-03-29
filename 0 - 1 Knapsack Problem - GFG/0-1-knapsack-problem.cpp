//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int w,int wt[],int val[],int n,vector<vector<int>>&dp){
        if(i==0){
            if(wt[0]<=w){
                return val[0];
            }
            return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int not_pick=f(i-1,w,wt,val,n,dp);
        int pick=-1e9;
        if(wt[i]<=w) pick= val[i]+f(i-1,w-wt[i],wt,val,n,dp);
        return dp[i][w]=max(pick,not_pick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
         //memoization
        // vector<vector<int>>dp(n,vector<int>(W+1,-1));
        // return f(n-1,W,wt,val,n,dp);
        
        
        
        
       //tabulation
        vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++){
           dp[0][i] =val[0];
          //every weight greater than the wt of the first element of wt array can make us take the value at index 0 .
       }
       
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int not_pick=dp[i-1][j];
               int pick=-1e9;
               if(wt[i]<=j) pick=val[i]+dp[i-1][j-wt[i]];
               dp[i][j]=max(pick,not_pick);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends