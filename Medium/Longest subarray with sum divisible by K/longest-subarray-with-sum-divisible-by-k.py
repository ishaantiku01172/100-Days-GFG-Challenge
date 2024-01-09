#User function Template for python3
class Solution:
    def longSubarrWthSumDivByK (self, arr, n, K):
        remainder_ids = {0: -1}
        prefix_sum, max_length = 0, 0
        for i in range(n):
            prefix_sum += arr[i]
            r = prefix_sum % K
            if r in remainder_ids:
                max_length = max(max_length, i - remainder_ids[r])
            else:
                remainder_ids[r] = i
        return max_length



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

	for _ in range(0,int(input())):
		n, K = map(int ,input().split())
		arr = list(map(int,input().strip().split()))
		ob = Solution()
		res = ob.longSubarrWthSumDivByK(arr, n, K)
		print(res)




# } Driver Code Ends