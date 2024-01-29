//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:		
	
	char kthCharacter(int m, int n, int k)
    {
        string binary = "", result = "";
        
        if(m == 0)
            binary = "0";
        
        while(m) {
            binary += (m%2 + 48);
            m /= 2;
        }
        reverse(binary.begin(), binary.end());
        
        while(n--) {
            result = "";
            for(char c: binary) {
                if(c == '0')
                    result += "01";
                else
                    result += "10";
            }
            binary = result;
        }
       return binary[k-1];
    }
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int m, n, k;
   		cin >> m >> n >> k;

   	
        Solution ob;
   		cout << ob.kthCharacter(m, n, k) << "\n";
   	}

    return 0;
}
// } Driver Code Ends