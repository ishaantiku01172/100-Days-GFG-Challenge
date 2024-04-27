#User function Template for python3

from collections import deque

class Solution:
    
    def helper(self, x, y, n, m, u, d, count, mat):
        q = deque()
        q.append([x, y, u, d])
        
        while q:
            x, y, u, d = q.popleft()
            if -1<y-1 and mat[x][y-1]==".":
                mat[x][y-1]="#"
                self.count+=1
                q.append([x, y-1, u, d])
            if y+1<m and mat[x][y+1]==".":
                mat[x][y+1]="#"
                self.count+=1
                q.append([x, y+1, u, d])
            if -1<x-1 and mat[x-1][y]=="." and u>0:
                mat[x-1][y]="#"
                self.count+=1
                q.append([x-1, y, u-1, d])
            if x+1<n and mat[x+1][y]=="." and d>0:
                mat[x+1][y]="#"
                self.count+=1
                q.append([x+1, y, u, d-1])

    def numberOfCells(self, n, m, r, c, u, d, mat):
        if mat[r][c]=="#": return 0
        mat[r][c] = "#"
        self.count = 1
        self.helper(r, c, n, m, u, d, 0, mat)
        return self.count


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(int(input()))

    for tcs in range(t):

        n, m, r, c, u, d = [int(x) for x in input().split()]

        mat = []

        for i in range(n):
            matele = [x for x in input()]
            mat.append(matele)
        obj=Solution()
        print(obj.numberOfCells(n, m, r, c, u, d, mat))
# } Driver Code Ends