//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool>p(sum+1,0);
        vector<bool>c(sum+1,0);
        p[0]=c[0]=true;
        // vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
       
        if(arr[0]<=sum)p[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notpick=p[j];
                bool pick=false;
                if(j>=arr[i]){
                    pick=p[j-arr[i]];
                }
                c[j]=notpick|pick;
            }
            p=c;
        }
        return p[sum];
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends