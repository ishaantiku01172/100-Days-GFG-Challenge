//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    long long solver(int i, int j, int n, int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp) {
        
        if (i == n - 1 && j == n - 1) {
            if (k == arr[i][j]){
                return 1;
            }
            else{
                return 0;
            }
        }
    
        if (dp[i][j][k] != -1){
            return dp[i][j][k];
        }
    
        long long right = 0;
        long long down = 0;
    
        if (i + 1 <= n - 1 && k - arr[i][j] >= 0){
            right = solver(i + 1, j, n, k - arr[i][j], arr, dp);
        }
        if (j + 1 <= n - 1 && k - arr[i][j] >= 0){
            down = solver(i, j + 1, n, k - arr[i][j], arr, dp);
        }
    
        return dp[i][j][k] = right + down;
        
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solver(0, 0, n, k, arr, dp);
        
    }
    
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends