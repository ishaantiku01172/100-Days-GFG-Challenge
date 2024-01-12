//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   

public:

    int minIteration(int N, int M, int x, int y){    

        int tmp1 = N-x  + M-y; // n,m corner

        int tmp2 = x-1 + M-y; // 0,m corner

        int tmp3 = N-x + y-1; // n, 0 corner

        int tmp4 = x-1 + y-1;// 0,0 corner

        int ans = max(tmp1,max(tmp2,max(tmp3, tmp4)));

        return ans;

    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends