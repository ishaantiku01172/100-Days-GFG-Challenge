#User function Template for python3

class Solution:
    
    #Complete this function
    
    #Function to return the name of candidate that received maximum votes.
    def winner(self,arr,n):
        # Your code here
        # return the name of the winning candidate and the votes he recieved
        dic = {}
        for i in range(n):
            dic[arr[i]] = dic.get(arr[i], 0)+1
        max_value = max(dic.values())
        res = []
        for i in dic:
            if dic[i] == max_value:
                res.append(i)
        res.sort()
        return res[0],max_value


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T=int(input())
    for _ in range(T):
        
        n=int(input())
        arr=input().strip().split()
        
        result = Solution().winner(arr,n)
        print(result[0],result[1])
# } Driver Code Ends