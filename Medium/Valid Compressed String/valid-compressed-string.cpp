//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n=S.length(), m=T.length();
        int count=0, idx=0;
        for(int i=0; i<m; i++){
            if(isdigit(T[i])){
                count=(10*count)+(T[i]-'0');
            }else{
                if(count){
                    idx+=count;
                    if(S[idx]!=T[i])return 0;
                }else{
                    if(S[idx]!=T[i])return 0;
                    
                }
                count=0;
                idx++;
            }
        }
        if(count && n-idx!=count)return 0;
        if(count==0 && idx<n)return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends