//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v) {
        unordered_set<int> s;

        //checking in which rows, ALL Elements are ZERO
        for(int i=0; i<v.size(); i++){
            int f=0;
            for(int j=0; j<v[i].size(); j++){
                if(v[i][j]!=0){
                    f=1;
                    break;
                }
            }
            
            if(f==0){
                s.insert(i);
            }
        }
        
        int ans=-1;
        
        //for row=x, if column(i)= x, has all elements= 1 then Celebrity element is found
        for(auto it= s.begin(); it!=s.end(); it++){
            int row= *it;
            int f=1;
            for(int i=0; i<v.size(); i++){
                if(row!=i && v[i][row]!=1){
                    f=0;
                    break;
                }
            }
            
            if(f==1){
                ans= row;
                break;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends