#User function Template for python3

class Solution:
    def minRow(self,n,m,a):
        #code here
        b = []
        for row in a:
            b.append(sum(row))
        return b.index(min(b)) + 1    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        A=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            A.append(B)
        ob=Solution()
        print(ob.minRow(N,M,A))
# } Driver Code Ends