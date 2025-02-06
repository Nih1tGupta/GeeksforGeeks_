//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    // solve--->find(o(n exrta));
    int find(int x,vector<int>&in){
        for(int i=0;i<in.size();i++){
            if(in[i]==x)return i;
        }
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder,int n,int &preO,int Inst,int Inend){
        // base
        if(preO>n-1||Inst>Inend){return nullptr;}
        int tomake=preorder[preO++];
        Node* ele=new Node(tomake);
        // find position in inorder
        int pos=find(ele->data,inorder);
        
        // partition
        // left
        ele->left=solve(inorder,preorder,n,preO,Inst,pos-1);
        // right
        ele->right=solve(inorder,preorder,n,preO,pos+1,Inend);
        return ele;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preO=0;
        int n=inorder.size();
        int Inst=0;int Inend=n-1;
        Node*ans= solve(inorder,preorder,n,preO,Inst,Inend);
        return ans;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends