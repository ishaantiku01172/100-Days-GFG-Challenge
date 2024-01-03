#User function Template for python3

class Solution:
      def singleElement(self, arr, N):
        one,two=0,0
        for i in arr:
            two^=(one&i)
            one^=i
            common=~(one&two)
            one&=common
            two&=common
        return one

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.singleElement(arr,N))
# } Driver Code Ends