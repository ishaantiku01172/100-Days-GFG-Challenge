#User function Template for python3
class Solution:
    def minDifference(self, nums, n):
        total = sum(nums)
        ans = float('inf')
        
        dp = [[0] * (total + 1) for _ in range(n)]
        
        for i in range(n):
            dp[i][0] = 1
            
        dp[0][total] = 1
        
        for i in range(1, n):
            for j in range(1, total + 1):
                
                not_take = dp[i - 1][j]
                
                take = 0
                if j - nums[i] >= 0:
                    take = dp[i - 1][j - nums[i]]
                    
                dp[i][j] = take or not_take
                
        for i in range(total + 1):
            if dp[n - 1][i] == 1:
                ans = min(ans, abs(2 * i - total))
       
        return ans  


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.minDifference(arr, N)
		print(ans)

# } Driver Code Ends