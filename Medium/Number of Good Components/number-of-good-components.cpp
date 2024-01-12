//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cnt=0;
    int cnt1=1;
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        cnt+=(adj[node].size());
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                cnt1++;
                dfs(it,adj,vis);
            }
        }
    }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        // code here
        vector<int> vis(v+1,0);
        int res=0;
        for(int i=1;i<=v;i++)
        {
            if(!vis[i])
            {
                cnt1=1;
                cnt=0;
                dfs(i,adj,vis);
                if(cnt==(cnt1*(cnt1-1)))
                   res++;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends