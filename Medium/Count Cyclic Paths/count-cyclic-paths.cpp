//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   

public:

    int countPaths(int N){

        // code here

       

       int f =1;

       long long ans=0;

       if(N==1) return 0;

       while(N>1)

        {  

            if(f==1){

                ans= (ans*3)+3;

            }

            else{

                ans= (ans*3)-3;

            }

            f=!f;

         ans = ans%1000000007;

            N--;

        }

        

        return ans;

        

    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends