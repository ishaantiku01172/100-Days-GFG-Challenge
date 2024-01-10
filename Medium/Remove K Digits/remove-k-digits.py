#User function Template for python3

from collections import deque
import itertools
class Solution:

    def removeKdigits(self, S, K):
        # code here
        ans = deque()

        for c in S:
            while K>0 and ans and ans[-1]>c:
                K-=1
                ans.pop()
            ans.append(c)
        while K>0 :
            K-=1
            ans.pop()
            
        res="".join(ans).lstrip('0') or '0'
        
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()
        K = int(input())

        obj = Solution()

        ans = obj.removeKdigits(S, K)

        print(ans)


# } Driver Code Ends