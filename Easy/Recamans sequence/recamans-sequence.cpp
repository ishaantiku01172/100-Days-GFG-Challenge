//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    vector<int> recamanSequence(int n){
        vector<int>ans(n,-1);
        unordered_set<int>us;
        ans[0] = 0;
        for(int i=1;i<n;i++){
            int prev = ans[i-1];
            if(prev - i > 0 && us.find(prev - i) == us.end()){
            ans[i] = prev -i;
            }
            else ans[i] = prev+i;
            us.insert(ans[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends