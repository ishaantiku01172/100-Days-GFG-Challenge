#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        #code here
        arr=[0]*(n+m)
        for i in range(n):
            arr[i]=arr1[i]
        for i in range(m):
            arr[i+n]=arr2[i]
        arr.sort()
        for i in range(n):
            arr1[i]=arr[i]
        for i in range(m):
            arr2[i]=arr[i+n]



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n,m = map(int, input().strip().split())
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob=Solution()
        ob.merge(arr1, arr2, n, m)
        print(*arr1,end=" ")
        print(*arr2)
# } Driver Code Ends