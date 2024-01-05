#User function Template for python3
class Solution:
    def singleElement(self, arr, N):
        # code here 
        element_count = {}
    
        for i in range(N):
            if arr[i] in element_count:
                element_count[arr[i]] += 1
            else:
                element_count[arr[i]] = 1
    
        for key, value in element_count.items():
            if value != 3:
                return key
    
        return 0


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