//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
        deque<int> ans1, ans2, ans;
        while (num1 != nullptr) {
            ans1.push_back(num1->data);
            num1 = num1->next;
        }
        while (num2 != nullptr) {
            ans2.push_back(num2->data);
            num2 = num2->next;
        }
        int n = ans1.size();
        int m = ans2.size();
        int k = abs(n - m);
        if (n <= m) {
            while (k--)
                ans1.push_front(0);
        } else {
            while (k--)
                ans2.push_front(0);
        }
        int carry = 0;
        for (int i = ans1.size()-1; i >=0; --i) {
            int sum = ans1[i] + ans2[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry)
            ans.push_back(carry);
        for (int i = ans.size()-1; i >=0; --i) {
            if(ans[i]==0){
                ans.pop_back();
            }
            else{
                break;
            }
        }
        int d=ans.size();
        if(d==0){
            ans.push_back(0);
        }
        Node* result = nullptr;
        Node* prevNode = nullptr;
        for (int i = ans.size() - 1; i >= 0; --i) {
            Node* newNode = new Node(ans[i]);
            newNode->next = nullptr;
            if (result == nullptr) {
                result = newNode;
            } else {
                prevNode->next = newNode;
            }
            prevNode = newNode;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends