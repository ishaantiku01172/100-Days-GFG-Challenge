//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count =0;
        
        for(int i =0; i<=n ;i++){
            int x = i;
            
            while(x>0){
                int d = x%10;
                if(d == 4){
                    count++;
                    break;
                }
                else{
                    x =x/10;
                }
            }            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends