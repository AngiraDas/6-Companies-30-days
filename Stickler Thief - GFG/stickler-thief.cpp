//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int money(int arr[],int n){
       
        int prev1=arr[0];
        int prev2=0;
        int present=INT_MIN;
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1){
                pick+=prev2;
            }
            int not_pick=prev1;
           int  present=max(pick,not_pick);
            prev2=prev1;
            prev1=present;
        }
        return prev1;
    }
      
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==1){
            return arr[0];
        }
        vector<int>v1,v2;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                v1.push_back(arr[i]);
                
            }
            if(i!=0){
                v2.push_back(arr[i]);
               
            }
        }
       
       
        int ans=money(arr,n);
        return ans;
        // Your code here
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends