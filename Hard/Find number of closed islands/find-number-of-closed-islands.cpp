//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,-0,1,-1};
    void dfs(int r,int c,int N,int M,vector<vector<int>>& matrix,bool &answer)
    {if(c==1 && matrix[r][c-1]==1)
        answer=false;
        if(c==M-2 && matrix[r][c+1]==1)
        answer=false;
        if(r==1 && matrix[r-1][c]==1)
        answer=false;
        if(r==N-2 && matrix[r+1][c]==1)
        answer=false;
        matrix[r][c]=0;
        for(int i=0;i<4;i++)
        {int newr=r+dx[i];
            int newc=c+dy[i];
            if(newr>=1 && newr<N-1 && newc>=1 && newc<M-1 && matrix[newr][newc]==1)
            dfs(newr,newc,N,M,matrix,answer);} 
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int no_of_islands=0;
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {   bool island=true;
               if(matrix[i][j]==1 )
                { dfs(i,j,N,M,matrix,island);
                    if(island)
                    no_of_islands++;}}}
        return no_of_islands;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends