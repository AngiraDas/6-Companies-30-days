//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        stack<char>st;
        string res;
        for(auto i:s)
        {
            if(i==')'){
                st.pop();
            }
            if(!st.empty()){
                res+=i;
            }
            if(i=='('){
                st.push(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends