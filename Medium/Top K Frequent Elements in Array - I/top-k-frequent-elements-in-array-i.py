class Solution:
    def topK(self, nums, k):
        #Code here
        count={}
        for num in nums:
            if num in count:
                count[num]+=1
            else:
                count[num]=1
        ans = sorted(count.keys(), key=lambda x: (-count[x], -x))
        return ans[:k]
#{ 
 # Driver Code Starts
		
if __name__ == '__main__':
    T=int(input())
    for i in range(T):
    	a = list(map(int, input().strip().split()))
    	n = a[0]
    	nums = a[1:]
    	k = int(input().strip())
    	obj = Solution()
    	ans = obj.topK(nums, k)
    	for i in ans:
    		print(i, end = " ")
    	print()
    	
# } Driver Code Ends