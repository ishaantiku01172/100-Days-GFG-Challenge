//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int>mp;
        for(auto i: arr)
        mp[i]++;
        
        int ans = 0; // find repeated number
        for(auto i: mp){
            if(i.second > 1){
                ans = i.first;
                break;
            }
        }
        set<int>s1(arr.begin(),arr.end());
        
        int missing = 0;
        for(int i = n; i>=1; i--){
            if(s1.find(i) == s1.end()){
                missing = i; // find missing number
                break;
            }
        }
        return {ans,missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends