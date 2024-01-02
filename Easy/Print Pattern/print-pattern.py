#User function Template for python3

class Solution:
    def pattern(self, N):
        # code here
        arr = []
        num = N
        if num == 0:
            arr.append(0)
            return arr
        arr.append(num)
        while(num>=0 and num != 0):
            num = num-5
            arr.append(num)
        while(num<=N):
            num += 5
            arr.append(num)
        return arr[0:len(arr)-1]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        ans = ob.pattern(N)
        for i in ans:
            print(i, end = " ")
        print()
# } Driver Code Ends