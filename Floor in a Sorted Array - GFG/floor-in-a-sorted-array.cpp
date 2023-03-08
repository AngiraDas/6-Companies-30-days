//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
       int mid=0,f=-1;
    int l=0;
      int r=n-1;
      if(x<v[0]){
          return -1;
      }
      else if(x>v[n-1]){
          return n-1;
      }
      else{
       for(int i=0;i<n;i++){
           
            mid=(l+r)/2;
            if(v[mid]<x){
                l=mid+1;
            }
            else if(v[mid]>x){
                r=mid-1;
            }
            else{
                if(v[mid]==x){
                    f=mid;
                }
            }
       }
       if(f!=-1){
           return f;
       }
       else{
           return l-1;
       }
        
      }
        // Your code here
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends