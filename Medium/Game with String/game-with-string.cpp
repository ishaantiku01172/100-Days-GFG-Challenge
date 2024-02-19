//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int minValue(string s, int k){
        // calculate frequency of each character
        map<char, int> frequency;
        for(int i = 0; i < s.length(); i++) {
            frequency[s[i]]++;
        }
        
        // store frequency of each character in priority queue (max heap)
        priority_queue<int> pq;
        for(auto &i: frequency){
            pq.push(i.second);
        }
        
        // decrement max frequencies by 1
        // and push them in queue until k != 0
        while(k != 0){
            int element = pq.top() - 1;
            k--;
            pq.pop();
            pq.push(element);
        }
        
        // calculate the squares of each element in the queue
        // and add them and return the final answer 
        int sum = 0;
        while(!pq.empty()){
            sum += pow(pq.top(), 2);
            pq.pop();
        }
        return sum;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends