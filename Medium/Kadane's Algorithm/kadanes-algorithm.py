#User function Template for python3

class Solution:
     def maxSubArraySum(self,arr,N):
        ##Your code here
        maxi=arr[0]
        prefix=0
        for i in range(N):
            prefix+=arr[i]
            maxi=max(maxi,prefix)
            if(prefix<0):
                prefix=0
        return maxi
 # Driver Code Starts
#Initial Template for Python 3

import math

 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends