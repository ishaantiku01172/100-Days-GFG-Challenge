//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{

    public:

    int findSubString(string str)

    {

        vector<int> arr(256, 0); // Initialize an array to store character frequencies

        int start = 0, end = 0, counter = 0, minLen = INT_MAX; // Initialize variables

 

        // Count the distinct characters in the string

        for (int i = 0; i < str.length(); i++) {

            if (arr[str[i]] == 0) {

                arr[str[i]]++;

                counter++;

            }

        }

 

        while (end < str.length()) {

            char curr = str[end];

 

            // If the character frequency is positive, decrease the counter

            if (arr[curr] > 0)

                counter--;

 

            arr[curr]--;

            end++;

 

            while (counter == 0) {

                // Update the minimum length if a shorter substring is found

                if (minLen > end - start) {

                    minLen = end - start;

                }

 

                char ch = str[start];

                arr[ch]++;

 

                // If the character frequency becomes positive, increase the counter

                if (arr[ch] > 0)

                    counter++;

 

                start++;

            }

        }

 

        return minLen;

    }

};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends