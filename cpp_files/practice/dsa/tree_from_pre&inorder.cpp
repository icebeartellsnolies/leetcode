// c++ program to construct tree using 
// inorder and preorder traversals
#include <iostream>
using namespace std;
#include <vector>

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the index of an element.
int searchValue(vector<int>& in, int value, int s, int e) {
    
    for (int i=s; i<=e; i++) {
        if (in[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the binary tree.
Node* buildTreeRecur(vector<int>& in, vector<int>& pre, int &preIndex, int s, int e) {
    
    // For empty array, return null
    if (s > e) return nullptr;
    
    // create the root Node
    Node* root = new Node(pre[preIndex]);
    preIndex++;
    
    // find the index of first element of pre-order array
    // in the in-order array.
    int index = searchValue(in, pre[preIndex-1], s, e);
    
    // Recursively create the left and right subtree.
    root->left = buildTreeRecur(in, pre, preIndex, s, index-1);
    root->right = buildTreeRecur(in, pre, preIndex, index+1, e);
    
    return root;
}

Node* buildTree(vector<int>& in, vector<int>& pre) {
    
    // Build the tree recursively.
    int n = pre.size();
    int preIndex = 0;
    Node* root = buildTreeRecur(in, pre, preIndex, 0, n-1);
    
    return root;
}



int main() {
    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> pre = {0, 1, 3, 4, 2, 5};
    Node* root = buildTree(in, pre);

    return 0;
}