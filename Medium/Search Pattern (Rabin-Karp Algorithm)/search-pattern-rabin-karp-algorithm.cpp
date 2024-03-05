//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
       vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> ans;
            int n = text.size();
            int m = pattern.size();
            
            // Iterate through the text
            for(int i=0; i<n; i++){
                
                bool match = true;
                
                // Iterate through the pattern and text, 
                // If they are not equal then break
                for(int j=0; j<m; j++)
                    if(text[i+j] != pattern[j]){
                        match = false;
                        break;
                    }
                    
                // If they are equal then add it to the ans
                if(match==true)
                    ans.push_back(i+1);
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends