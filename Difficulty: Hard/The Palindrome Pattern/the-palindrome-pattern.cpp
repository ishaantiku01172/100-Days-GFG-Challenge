//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool palin(const vector<int>& v) {
    int n = v.size();
    for (int j = 0; j < n / 2; j++) {
        if (v[j] != v[n - j - 1]) {
            return false;
        }
    }
    return true;
}

bool palinColumn(const vector<vector<int>>& arr, int colIndex) {
    int n = arr.size();
    for (int j = 0; j < n / 2; j++) {
        if (arr[j][colIndex] != arr[n - j - 1][colIndex]) {
            return false;
        }
    }
    return true;
}

string pattern(vector<vector<int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (palin(arr[i])) {
            return to_string(i) + " R";
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (palinColumn(arr, i)) {
            return to_string(i) + " C";
        }
    }
    
    return "-1"; 
}
    
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends