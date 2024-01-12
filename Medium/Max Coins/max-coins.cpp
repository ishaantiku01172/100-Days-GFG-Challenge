//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n , vector<vector<int>> &r ) {
        vector< int > maxi( n , 0 ) , st( n , 0 ) ;
        sort( r.begin() , r.end() ) ;
        int ans = INT_MIN ;
        
        for( int i = n-1 ; i>=0 ; i-- ){
            maxi[i] = r[i][2] ;
            st[i] = r[i][0] ;
            if( i < n-1 )
               maxi[i] = max( maxi[i] , maxi[i+1] ) ;
        }
        for( int i = 0 ; i< n; i++ ){
             int x = r[i][1] ;
             ans = max( ans , r[i][2] ) ;
             auto c = lower_bound( st.begin()+(i+1) , st.end() , x ) ;
             if( c != (st.end()) ){
                  int j = c-st.begin() ;
                  ans = max( ans , r[i][2] + maxi[j] ) ;
                  
             }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends