//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        vector<long long> vec = {9, 1, 3, 5, 7};
        stack<long long> G;
        while(N){
            if(N%5 == 0){
                G.push(vec[N%5]);   
                N = N/5;
                N--;
            }
            else{
                G.push(vec[N%5]); 
                N = N/5;
            }
        }
        long long dig = 0;
        while(!G.empty()){
            dig = G.top()*pow(10, G.size()-1) + dig;
            G.pop();
        }
        return dig; 
    }


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends