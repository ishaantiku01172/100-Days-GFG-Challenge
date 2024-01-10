#User function Template for python3
class Solution:
	
	def findMaxSum(self,arr, n):
		
		if n==1:
		    return arr[0]
		
		temp1=arr[0]
		temp2=arr[1]
		res=max(temp1,temp2)
		
		for i in range(2,n):
		    temp2=temp1+arr[i]
		    temp1=res
		    res=max(temp1,temp2)
		    
		return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3




if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaxSum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends