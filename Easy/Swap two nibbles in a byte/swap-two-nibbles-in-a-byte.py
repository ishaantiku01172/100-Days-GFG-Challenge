#User function Template for python3
class Solution:
    def swapNibbles (self, n):

        # code here 

        m=n>>4

        p=15&n

        m=p<<4|m

        return m
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        print(ob.swapNibbles(n))

# } Driver Code Ends