#User function Template for python3

class Solution:
	def TotalWays(self, N):
		# Code here
		x=y=1
		mod=10**9+7
		for i in range(2,N+1):
		    z=y
		    y=(x+y)%mod
		    x=z%mod
		return (((x+y)%mod)*((x+y)%mod))%mod
#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.TotalWays(N)
		print(ans)
# } Driver Code Ends