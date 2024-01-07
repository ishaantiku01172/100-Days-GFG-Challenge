#User function Template for python3

class Solution:
    def mergeResult(self, h1, h2):
        #return head of merged list
        l = []
    
        ptr1 = h1
        ptr2 = h2
        
        while(ptr1):
            l.append(ptr1.data)
            ptr1 = ptr1.next
            
        while(ptr2):
            l.append(ptr2.data)
            ptr2 = ptr2.next
            
        l.sort()
        l.reverse()
        if len(l)==0:
            return None
            
        h3 = Node(l[0])
        ptr3 = h3
        for i, v in enumerate(l):
            if i != 0:
                new = Node(v)
                ptr3.next = new
                ptr3 = new
                
        return h3
#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node
        

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next
        
if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        
        n1,n2=[int(x) for x in input().split()]
        
        arr1=[int(x) for x in input().split()]
        ll1=Llist()
        tail=None
        for nodeData in arr1:
            tail=ll1.insert(nodeData,tail)
            
            
        arr2=[int(x) for x in input().split()]
        ll2=Llist()
        tail=None
        for nodeData in arr2:
            tail=ll2.insert(nodeData,tail)
        
        
        ob = Solution()
        resHead=ob.mergeResult(ll1.head,ll2.head)
        printList(resHead)
        print()
        
    
    
# } Driver Code Ends