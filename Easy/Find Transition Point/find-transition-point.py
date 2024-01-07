class Solution:
    def transitionPoint(self, arr, n): 
        if arr[0]==0:
          for i in range(n-1):
              if arr[i]==1:
                  return i
          return -1
        else:
             i=0
             while  i<=n-1:
                 if arr[i]==0:
                     return None
                 i=i+1   
             return 0

#{ 
 # Driver Code Starts
#driver code
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.transitionPoint(arr, n))

# } Driver Code Ends