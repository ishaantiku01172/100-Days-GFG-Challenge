#User function Template for python3

class Solution:
    def sortedArrayToBST(self, nums):
        
        def solve(l,r):
            
            if l > r: return None
            
            mid = l+(r-l)//2
            
            root = Node(arr[mid])
            
            root.left = solve(l,mid-1)
            root.right = solve(mid+1,r)
            
            return root
            
            
        return solve(0,len(nums)-1)

#{ 
 # Driver Code Starts
from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def help(root, up, l):
    if root.data >= up or root.data <= l:
        return False
    ans = True
    if root.left:
        ans = help(root.left, root.data, l)
    if ans and root.right:
        ans = help(root.right, up, root.data)
    return ans


def isValidBST(root):
    return help(root, 3147483648, -3147483649)


def height(root):
    if root is None:
        return 0
    leftHeight = height(root.left)
    rightHeight = height(root.right)
    if leftHeight == -1 or rightHeight == -1 or abs(leftHeight -
                                                    rightHeight) > 1:
        return -1
    return max(leftHeight, rightHeight) + 1


def isBalanced(root):
    if root is None:
        return True
    return height(root) != -1


def inorder(root, v):
    if root is None:
        return
    inorder(root.left, v)
    v.append(root.data)
    inorder(root.right, v)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))

        solution = Solution()
        root = solution.sortedArrayToBST(arr)

        v = []
        inorder(root, v)

        if not isValidBST(root) or v != arr:
            print("false")
            continue

        if isBalanced(root):
            print("true")
        else:
            print("false")

# } Driver Code Ends