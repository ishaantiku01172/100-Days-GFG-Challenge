//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:

    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); 
    }
    
    bool Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return true;
        if (rank[a] >= rank[b])
        {
            rank[a]++;
            parent[b] = a;
        }
        else
        {
            rank[b]++;
            parent[a] = b;
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int i = 0; i < m; i++)
            if (Union(adj[i][0], adj[i][1])) return 0;
        int cnt = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) st.insert(find(i));
        return st.size() == 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends