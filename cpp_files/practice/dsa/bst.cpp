#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class BTree{
	struct BTNode{
		int val;
		BTNode *left, *right;
		BTNode(int val, BTNode *left = NULL, BTNode *right = NULL){
			this->val = val;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BTree(){		root = NULL;	 }

    BTNode* insert(int value, BTNode *temp){	
		if (!temp)	return new BTNode(value);
		if(value<temp->val)
            temp->left = insert(value,temp->left);
        else
            temp->right = insert(value,temp->right);				
		return temp;
	}
	void insert(int value){		
        root = insert(value, root);
    }

    void generateTree(BTNode *temp, int tabs = 0){
		if (!temp)	return;
		generateTree(temp->right, tabs + 1);
		for (int i = 0 ; i < tabs ; i++)	cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
    void generateTree(){		generateTree(root);	}
    
    BTNode* search(BTNode *root, int value){
        if(!root) return NULL;
        if (root->val==value)
            return root;
        if (value>root->val)
            return search(root->right, value);
        else
            return search(root->left, value);
    }
    BTNode* search(int value){
       return search (root, value);
    }

    void delNode(int value){
        root = delNode (root, value);
    }
    BTNode* delNode (BTNode* root,int value){
        if (!root) return NULL;
        // 2 children:
        if (value < root->val)
            root->left= delNode (root->left, value);
        else if (value > root->val)
            root->right=delNode(root->right,value);
        // no child:
        else if (!root->left && !root->right){
            delete root; 
            return NULL;
        }
        // 1 child:
        else if (!root->left){
            BTNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right){
            BTNode* temp = root->left;
            delete root;
            return temp;
        }
        // when the curr node has 2 children and we have already given the recursive calls and we
        // have the found the node whose val is equal to value
        else{
            BTNode* temp = find_smallest(root->right);
            root->val = temp->val;
            root->right=delNode(root->right, temp->val);
        }
        return root;
    }

    BTNode* find_smallest(BTNode *curr){
        if(!curr->left) return curr;
        return find_smallest(curr->left);
    }

    void sorted_array_to_bst(int arr[], int len){
        BTNode* new_root = sorted_array_to_bst(root, arr, 0, len-1);
        generateTree(new_root);
    }

    BTNode* sorted_array_to_bst(BTNode *curr, int arr[],int start, int end){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        BTNode* temp = new BTNode(arr[mid]);
        temp->left = sorted_array_to_bst(temp,arr, start, mid-1);
        temp->right = sorted_array_to_bst(temp,arr, mid+1, end);
        return temp;
    }
    
    void node_with_val_matched(int value){
        BTNode*temp= node_with_val_matched(root, value);
        generateTree(temp);
    }
    BTNode* node_with_val_matched(BTNode* curr, int value){
        if (!curr) 
            return NULL;
        if (curr->val==value)
            return curr;
        if (value>curr->val)
            return node_with_val_matched(curr->right, value);
        return node_with_val_matched(curr->left, value);
    }
    void make_ascending(){
        vector<int>v;
        inorder(v, root);
        BTNode* ans = make_ascending(v);
        generateTree(ans); 
    }
    void inorder(vector<int>&v, BTNode*curr){
        if(!curr) return;
        inorder(v,curr->left);
        v.push_back(curr->val);
        inorder(v,curr->right);
    }
    BTNode* make_ascending(vector<int>v){
        BTNode* curr = new BTNode(v[0]);
        BTNode *ans = curr;
        for(int n=1;n<v.size();n++){
            BTNode* temp  = new BTNode(v[n]);
            curr->right = temp;
            curr=curr->right;
        }
        return ans;
    }
    
};

int main(){
    BTree t1;
    t1.insert(70);
    t1.insert(120);
    t1.insert(30);
    t1.insert(50);
    t1.insert(65);
    t1.insert(40);
    t1.insert(55);
    t1.insert(10);
    t1.insert(20);
    t1.insert(3);
    t1.insert(7);
    t1.insert(0);
    // t1.generateTree();
    // t1.generateTree();
    // t1.delNode(30);
    // t1.generateTree();
    // int arr[5]={-10,-3,0,5,9};
    
    // cout<<t1.node_with_val_matched(30);
    // t1.node_with_val_matched(30);
    // t1.make_ascending();
    BTree t2;
    int arr[5]={-10,-3,0,5,9};
    t2.sorted_array_to_bst(arr,5);
    
    return 0;
}