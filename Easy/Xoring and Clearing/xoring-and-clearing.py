#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def printArr(self, n, arr):
        # printing array elements with spaces
        return 

    def setToZero(self, n, arr):
        # setting all elements to zero
        ans = [0]*n
        for i  in range(n):
            if i == n-1 : 
                print(ans[i])
            else : print(ans[i] , end=" ")
            

    def xor1ToN(self, n, arr):
        # doing xor with indices
        x=[arr[i]^(i) for i in range(n)]
        for i in range(n):
            if i == n-1 : 
                print(x[i])
            else : print(x[i] , end=" ")
            

#{ 
 # Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        obj = Solution()
        obj.xor1ToN(n, arr)
        obj.printArr(n, arr)
        obj.setToZero(n, arr)
        obj.printArr(n, arr)

# } Driver Code Ends