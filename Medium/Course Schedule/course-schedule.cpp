//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    class graph
    {
        int vertex;
        list<int> *l;

    public:
        graph(int v)
        {
            this->vertex = v;
            l = new list<int>[vertex];
        }

        void edge(int i, int j, bool directed = false)
        {
            l[i].push_back(j);
            if (directed)
            {
                l[j].push_back(i);
            }
        }

        vector<int> topologicalsort()
        {
            vector<int> degree(vertex, 0);

            for (int i = 0; i < vertex; i++)
            {
                for (auto nbr : l[i])
                {
                    degree[nbr]++;
                }
            }

            queue<int> q;

            for (int i = 0; i < vertex; i++)
            {
                if (degree[i] == 0)
                {
                    q.push(i);
                }
            }

            vector<int> res;
            while (!q.empty())
            {
                int front = q.front();
                res.push_back(front);
                q.pop();

                for (auto nbr : l[front])
                {
                    degree[nbr]--;
                    if (degree[nbr] == 0)
                    {
                        q.push(nbr);
                    }
                }
            }
            return res;
        }
    };

    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        graph g(n);

        for (auto preq : prerequisites)
        {
            g.edge(preq[1], preq[0]);
        }

        vector<int> result = g.topologicalsort();

        if (result.size() != n)
        {
            return vector<int>();
        }

        return result;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends