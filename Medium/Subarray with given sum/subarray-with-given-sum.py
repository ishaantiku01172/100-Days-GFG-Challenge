#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self,arr, n, s):
        sum1=0
        b=0
        e=-1
        for i in range(n):
            sum1=sum1+arr[i]
            while(sum1>s):
                sum1=sum1-arr[b]
                b=b+1
            if(sum1 == s):
                e=i
                break
        if (sum1!=s or b>e):
            return [-1]
        return [b+1,e+1]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends