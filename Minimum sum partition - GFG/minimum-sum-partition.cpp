//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int s=0;
	    for(int i=0;i<n;i++) s+=arr[i];
     
        vector<bool>p(s+1,0),c(s+1,0);
        p[0]=c[0]=true;
        if(arr[0]<=s) {
            p[arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                bool notpick=p[j];
                bool pick=false;
                if(arr[i]<=j){
                    pick=p[j-arr[i]];
                }
                c[j]=pick|notpick;
            }
            p=c;
        }
        int ans=1e9;
        for(int i=0;i<=(s/2);i++){
            if(p[i]==true){
                int s1=i;
                int s2=s-i;
                ans=min(ans,abs(s2-s1));
            }
        }
        return ans;
	   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends