//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       

   vector<int>dis(V,1e9);
   dis[S]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
   q.push({0,S});
//    vector<pair<int,int>> adj[vertices];

//     for(int i=0;i<edge.size();i++){

//         int u=edge[i][0];

//         int v=edge[i][1];

//         int wt=edge[i][2];

//         adj[u].push_back({v,wt});

//         adj[v].push_back({u,wt});

//     }


   while(!q.empty()){
       int node=q.top().second;
       int d=q.top().first;

       q.pop();
       for(auto it:adj[node]){
           int edgeWeight=it[1];
           int edgeNode=it[0];
           if(d+edgeWeight<dis[edgeNode]){
               dis[edgeNode]=d+edgeWeight;
               q.push({dis[edgeNode],edgeNode});
           }
       }
   }
   return dis;

    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends