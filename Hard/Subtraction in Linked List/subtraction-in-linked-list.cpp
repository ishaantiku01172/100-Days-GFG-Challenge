//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* insertFront(Node *head,int data){
    if(!head){
        return new Node(data);
    }
    else{
        Node *newHead=new Node(data);
        newHead->next=head;
        head=newHead;
    }
    return head;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    string num1,num2;
    
    Node *trav=l1;
    while(trav && trav->data==0){
        trav=trav->next;
    }
    
    while(trav){
        num1.push_back('0'+trav->data);
        trav=trav->next;
    }
    trav=l2;
    while(trav && trav->data==0){
        trav=trav->next;
    }
    while(trav){
        num2.push_back('0'+trav->data);
        trav=trav->next;
    }
    int borrow=0;
    if(num1.size()>num2.size()){
        while(num2.size()<num1.size()){
            num2.insert(0,"0");
        }
    }
    else if(num1.size()<num2.size()){
        while(num2.size()>num1.size()){
            num1.insert(0,"0");
        }
        swap(num1,num2);
    }
    else if(num1.size()==num2.size()){
        int i=0;
        while(num1[i]==num2[i]){
            i++;
        }
        if(num1[i]<num2[i]) swap(num1,num2);
    }
    int ind=num1.size()-1;
    Node *ans=nullptr;
    while(ind>=0){
        int n1=num1[ind]-'0';
        int n2=num2[ind]-'0';
        if(n1<n2+borrow){
            int number=n1+10-borrow-n2;
            ans=insertFront(ans,number);
            borrow=1;
        }
        else{
            int number=n1-borrow-n2;
            ans=insertFront(ans,number);
            borrow=0;
        }
        ind--;
    }
    trav=ans;
    while(trav && trav->data==0){
        trav=trav->next;
    }
    ans=trav;
    if(!ans) ans=insertFront(ans,0);
    return ans;
}
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends