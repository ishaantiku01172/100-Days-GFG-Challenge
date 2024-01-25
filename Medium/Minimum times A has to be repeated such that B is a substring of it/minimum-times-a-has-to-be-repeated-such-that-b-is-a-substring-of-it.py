#User function Template for python3

class Solution:
    def minRepeats(self, A, B):
        la = len(A)
        lb = len(B)
        i = 1 
        while True:
            C = A*i
            if B in C:
                return i 
            if la*i > lb and i > 1:
                return -1
            i += 1
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        A=input()
        B=input()
        
        ob = Solution()
        print(ob.minRepeats(A,B))
# } Driver Code Ends