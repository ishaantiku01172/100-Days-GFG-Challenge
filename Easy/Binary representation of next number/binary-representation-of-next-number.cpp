//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string str)
{
    // code here.
    int i = 0;
    while (str[i] == '0')
    {
        i++;
    }
    str.erase(0, i);
 
    int len = str.length();
    bool flag = true;
    while (flag and len > 0)
    {
        int lastIndex = len - 1;
        if (str[lastIndex] == '1')
        {
            str[lastIndex] = '0';
            len--;
        }
        else
        {
            str[lastIndex] = '1';
            flag = false;
            break;
        }
    }
    if (flag)
    {
        string str1 = "1";
        str1 = str1 + str;
        return str1;
    }
    return str;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends