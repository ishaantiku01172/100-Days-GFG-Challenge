//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   

public:

    int minCost(vector<vector<int>> &cl, int N) {

         for(int i=1;i<N;i++){

            cl[i][0]=cl[i][0]+min(cl[i-1][1],cl[i-1][2]); 

            cl[i][1]=cl[i][1]+min(cl[i-1][0],cl[i-1][2]); 

            cl[i][2]=cl[i][2]+min(cl[i-1][0],cl[i-1][1]); 

         }

    return min(cl[N-1][0],min(cl[N-1][1],cl[N-1][2]));

    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends