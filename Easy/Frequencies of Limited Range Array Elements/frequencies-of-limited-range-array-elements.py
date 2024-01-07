class Solution:
    def frequencyCount(self, arr, N, P):
        f = [0] * N
        for i in arr:
            if 1 <= i <= N:
                f[i - 1] += 1
        arr[:] = f
        return arr
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
if __name__=="__main__":
	T=int(input())
	while(T>0):
		N=int(input())
		arr=[int(x) for x in input().strip().split()]
		P=int(input())
		ob=Solution()
		ob.frequencyCount(arr, N, P)
		for i in arr:
			print(i, end=" ")
		print()
		T-=1



# } Driver Code Ends