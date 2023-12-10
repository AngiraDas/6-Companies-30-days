//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           pair<int,int>p=make_pair(end[i],start[i]);
           v.push_back(p);
       }
       sort(v.begin(),v.end());
       int c=1;
       int endtime=v[0].first;
       for(int i=1;i<n;i++){
           if(v[i].second>endtime){
               c++;
               endtime=v[i].first;
           }
       }
       return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends