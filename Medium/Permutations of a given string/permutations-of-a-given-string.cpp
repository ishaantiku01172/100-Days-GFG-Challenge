//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
void swap(char &a,char &b)
{
    char c=a;
    a=b;
    b=c;
    
    
}
//vector<string> v;
set<string> set1;
void permute(string& a, int l, int r) 
    { 
    // Base case 
    if (l == r) 
      set1.insert(a); 
    else { 
        // Permutations made 
        for (int i = l; i <= r; i++) {  
            swap(a[l], a[i]); 
            permute(a, l + 1, r);
            swap(a[l], a[i]); 
        } 
    } 
} 
vector<string>find_permutation(string S)
{
    permute(S,0,S.size()-1);
    vector<string> v;
    for (auto& str : set1) {
            v.push_back(str);
               }
    return v;
    // Code here there
}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends