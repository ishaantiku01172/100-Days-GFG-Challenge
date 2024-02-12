//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        long long mul=1;
        long long count=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                mul=(mul*count)%1000000007;
                count++;
            }
            ans+=mul;
            mul=1;
            ans=ans%1000000007;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends