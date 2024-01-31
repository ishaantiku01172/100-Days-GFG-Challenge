//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    // int len=10002;
    vector<int> prime;
    vector<int> dis;
    int solve(int num1,int num2)
    {   
      //code here
      prime.resize(10002,1);
      dis.resize(10002,-1);
      for (int p = 2; p * p <= 10001; p++) {
            if (prime[p] == 1) {
                for (int i = p * p; i <= 10001; i += p)
                    prime[i] = 0;
            }
        }
        
        queue<int> q1,q2;
        dis[num1]=0;
        q1.push(num1);
        int d=0;
        while(!q1.empty())
        {
            d++;
            while(!q1.empty())
            {
                int num=q1.front();
                
                for(int i=0;i<=3;i++)
                {
                    int rem=num%((int)pow(10,i));
                    int temp=num/(int)pow(10,i+1);
                    temp=temp*((int)pow(10,i+1));
                    temp+=rem;
                    // cout<<temp<<"\n";
                    for(int j=0;j<=9;j++)
                    {
                        if(i==3 && j==0)
                            continue;
                        int nextnum=temp+(j*(int)pow(10,i));
                        if(prime[nextnum]==1 && dis[nextnum]==-1)
                        {
                            dis[nextnum]=d;
                            if(nextnum==num2)
                            return d;
                            
                            q2.push(nextnum);
                        }
                    // cout<<nextnum<<"\n";
                    }
                    
                }
                q1.pop();
            }
            q1=q2;
            q2=queue<int>();
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends