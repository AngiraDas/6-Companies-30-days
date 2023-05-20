//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void bfs(int vis[],vector<int>ls[],int node){
      vis[node]=1;
      queue<int>q;
      q.push(node);
      while(!q.empty()){
          int f=q.front();
          q.pop();
          for(auto it:ls[f]){
              if(!vis[it]){
                  vis[it]=1;
                  q.push(it);
              }
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>ls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&i!=j){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        int c=0;
        int vis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                c++;
                bfs(vis,ls,i);
            }
        }
        return c;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends