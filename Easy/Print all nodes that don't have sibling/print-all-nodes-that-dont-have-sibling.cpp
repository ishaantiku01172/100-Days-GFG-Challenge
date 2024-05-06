//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
vector<int> noSibling(Node *root);

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
  }
  return 0;
}

// } Driver Code Ends


//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

vector<int> noSibling(Node* node)
{
    // code here
    if(node == NULL) return {-1};
    
    vector<int> res;
    queue<pair<Node*,int>> q; //queue to store node and integer value 
    q.push(make_pair(node,0)); //store int value as 0 if node is root node or node has both child
    while(!q.empty()){
        int count = q.size();
        
        for(int i=0;i<count;i++){
            pair<Node*,int> p = q.front();
            Node* root =p.first;
            q.pop();
            if(p.second!=0) //push node data to vector if integer value is 1[not root node and node is single child]
            res.push_back(p.first->data);


            int flag = 1;
            if(root->left and root->right)
            flag =0; //if node has both child keep flag as 0 [ Node has siblings]
            
            if(root->left) q.push(make_pair(root->left,flag));  //push left node and flag in queue if left of node is not NULL
            if(root->right) q.push(make_pair(root->right,flag)); //push right node and flag in queue if right of node is not NULL
            
        }    
        
        
    }
    
    if(res.size()<1) return {-1};//if all nodes have siblings return -1
    
    sort(res.begin(),res.end()); //sort vector in increasing order
    return res;
}