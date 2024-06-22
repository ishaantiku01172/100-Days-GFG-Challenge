
class Solution:
    def ExtractNumber(self,sentence):
        x = sentence.split()

        l=[]
        for i in x:
            if i.isdecimal() and '9' not in i:
                l.append(int(i))
        if l:
            return max(l) if len(l) > 1 else l[0]
        else:
            return -1

#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends