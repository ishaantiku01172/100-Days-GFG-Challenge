#User function Template for python3

class Solution:
    def smallestSubstring(self, s):
        n = len(s)
        res = float('inf')
        prev = [float('-inf')] * 3
        for i in range(n):
            prev[int(s[i])] = i
            res = min(res, i - min(prev) + 1)
        if res == float('inf'):
            return -1
        return res
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	t=int(input())
	for i in range(t):
		S = input()
		ob = Solution()
		ans = ob.smallestSubstring(S)
		
		print(ans)



# } Driver Code Ends