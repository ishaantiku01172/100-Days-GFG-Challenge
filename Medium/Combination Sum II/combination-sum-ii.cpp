//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> combi;
    set<vector<int>> st;
    // vector<vector<int>> dp;
    vector<int> vec;
    int n, k;
    void dfs(int curr_ind, int temp_sum, vector<int> temp_vec){
        if(temp_sum == 0){
            if(st.find(temp_vec) == st.end()){
                combi.push_back(temp_vec);
                st.insert(temp_vec);
            }
            return;
        }
        for(int i = curr_ind; i < n; i++){
            if(temp_sum >= vec[i]){
                temp_vec.push_back(vec[i]);
                dfs(i + 1, temp_sum - vec[i], temp_vec);
                temp_vec.pop_back();
            }
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        this->vec = arr;
        this->n = arr.size();
        this->k = k;
        vector<int> temp_vec;
        dfs(0, k, temp_vec);
        return combi;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends