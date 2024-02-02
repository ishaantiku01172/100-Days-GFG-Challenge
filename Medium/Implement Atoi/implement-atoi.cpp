//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans = 0;
        int flag = 1;
        int n = s.size();
        if(s[0]=='-') flag = -1;
        for(int i = 0;i<n;i++){
            if(flag==-1 && i==0) continue;
            int x = s[i]-'0';
            if(x<0 || x>9) return -1;
            ans = ans*10+x;
        }
        return ans*flag;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends