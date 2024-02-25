#User function Template for python3


class Solution:
    
    #Function to find largest rectangular area possible in a given histogram.
     def getMaxArea(self, histogram):
        s, n = [], len(histogram)
        maxarea = 0
        for i in range(n):
            h = histogram[i]
            while s and histogram[s[-1]] > h:
                j = s.pop()
                start_i = s[-1] + 1 if s else 0
                maxarea = max(maxarea, histogram[j] * (i - start_i))
            s.append(i)
        while s:
            j = s.pop()
            start_i = s[-1] + 1 if s else 0
            maxarea = max(maxarea, histogram[j] * (n - start_i))
        return maxarea

#{ 
 # Driver Code Starts
#Initial Template for Python 3

# by Jinay Shah 

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        a = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.getMaxArea(a))
# } Driver Code Ends