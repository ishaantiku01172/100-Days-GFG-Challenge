//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    const int mod = 1e9+7;
    
    vector<long long> helperFunc(int n){
        if(n == 0) return {1};
        
        vector<long long> prevRow = helperFunc(n-1);
        
        vector<long long> currRow(n, 0);
        currRow[0] = 1; currRow[n-1] = 1;
        
        for(int i=1;i<n-1;i++){
            currRow[i] = (prevRow[i-1]+prevRow[i]) % mod;
        }
        
        return currRow;
    }
    
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> result = helperFunc(n);
        return result;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends