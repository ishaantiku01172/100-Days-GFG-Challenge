//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        int Maximize(vector<int> arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        long long int ans=0;
        long long mode = 1e9+7;
        for(long long int i=0;i<arr.size();i++){
            long long int t=(arr[i]*i)%mode;
            ans=(ans+t)%mode;
            
        }
        return (ans%mode);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends