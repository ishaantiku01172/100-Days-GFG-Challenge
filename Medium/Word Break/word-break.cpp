//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_map<char, int> umap;
        
        // Count the frequency of characters in the input string
        for (char i : s) umap[i]++;
        
        // Check each word in the dictionary
        for (string str : dictionary) {
            // Find the substring in the input string
            size_t found = s.find(str);
            
            // If the substring is found, update the frequency of characters
            while (found != string::npos) {
                for (char ch : str) umap[ch]--;
                found = s.find(str, found + 1); // Find the next occurrence
            }
        }
        
        // Check if all character frequencies are non-negative
        for (auto it : umap) {
            if (it.second > 0)
                return 0;
        }
        return 1;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends