//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     char nthCharacter(string s, int r, int n) {
        //code here
        int iter = 0;
         string ans = "";
         while(iter < r){
             for(int idx = 0; idx < n/2+1;idx++){
                 if(s[idx] == '1')
                  ans.append("10");
                 if(s[idx] == '0')
                  ans.append("01");
             }
             s = ans;
             ans = "";
             iter++;
         }
        
         return s.at(n);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends