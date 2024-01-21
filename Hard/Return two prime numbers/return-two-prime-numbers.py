#User function Template for python3

class Solution:
    def primeDivision(self, N):
        isPrime = [True]*(N+1)
        i = 2
        while i*i <= N:
            if isPrime[i] and i*i <= N:
                for j in range(i*i,N+1,i):
                    isPrime[j] = False
            i += 1
        num1,num2 = 0,0
        for i in range(2,N):
            if isPrime[i] == True:
                num1 = i
                num2 = N-i
                if isPrime[N-i] == True:
                    break
        return num1,num2


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        p1, p2 = ob.primeDivision(N)
        print(p1,end=" ")
        print(p2)
# } Driver Code Ends