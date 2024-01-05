//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> res;
        for (int k = 0; k < q; k++) {
            int hop = queries[k][0];
            int i = queries[k][1], j = queries[k][2];
            int sum = 0;

            for (int x = i - hop; x <= i + hop; x++) {
                for (int y = j - hop; y <= j + hop; y++) {
                    if (x == i - hop || x == i + hop || y == j - hop || y == j + hop) {
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            sum += mat[x][y];
                        }
                    }
                }
            }

            res.push_back(sum);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends