//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize)
            return false;
        else if(groupSize==1)
            return true;
        map<int,int>mp;
        for(auto i:hand)
            mp[i]++;
        for(auto i:mp)
            if(mp[i.first]>0)
                for(int j=groupSize-1;j>=0;j--){
                    mp[i.first+j]-=mp[i.first]; //Explanation above
                    if(mp[i.first+j]<0)
                        return false;
                }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends