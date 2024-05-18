#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include<map>
#include <queue>
#include <cmath>

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
        inorder_vector(v, root);
        BTNode* ans = make_ascending(v);
        generateTree(ans); 
    }
    void inorder_vector(vector<int>&v, BTNode*curr){
        if(!curr) return;
        inorder_vector(v,curr->left);
        v.push_back(curr->val);
        inorder_vector(v,curr->right);
    }

    BTNode* equal_subtree(vector<int>&v,BTNode*root){
        if(!root) return NULL;
        vector <int> ans;
        inorder_vector(ans,root);
        vector <bool> trues;
        for(int n=0;n<ans.size(); n++){
            if (ans[n]==v[n]){
                trues.push_back(1);
            }
        }
        if (trues.size()==ans.size()) return root;
        BTNode *left = equal_subtree(v,root->left);
        if (left) return root;
        return equal_subtree(v,root->right);
    }
    void equal_subtree(vector<int>&list){
        sort(list.begin(), list.end());
        BTNode *a = equal_subtree(list, root);
        generateTree(a);
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
    void preorder_vector(vector<int>&v,BTNode *root){
        if(!root) return;
        v.push_back(root->val);
        preorder_vector(v,root->left);
        preorder_vector(v,root->right);
    }

    BTNode* positive_only(BTNode*root){
        
        if(!root) return NULL;
        vector<int>v;
        preorder_vector(v,root);
        int pos_count=0;
        for(int n:v){
            if(n>=0){
                pos_count++;
            }
        }
        if (pos_count==v.size()) return root;
        BTNode *left =(root->left);
        if (left && root->val>=0)return left;
        return positive_only(root->right);
    }

    void pos_tree(){
        BTNode*a=positive_only(root);
        generateTree(a);
    }

    void node_with_sum(BTNode *root, map<BTNode*,int> &m ){
        vector <int> all;
        if(!root) return;
        preorder_vector(all,root);
        int sum =0;
        for(int n:all){
            sum+=n;
        }
        m[root]=sum;
        node_with_sum(root->left, m);
        node_with_sum(root->right, m);
    }
    BTNode *max_node_sum(){
        map<BTNode*,int> m;
        node_with_sum(root, m);
        int max_sum=INT_MIN;
        BTNode* max_node = root;
        for(auto & i: m){
            if(i.second>max_sum){
                max_sum=i.second;
                max_node=i.first;
            }
        }
        return max_node;
    }
    void max_node(){
        BTNode*a = max_node_sum();
        generateTree(a);
    }

    int max_levels(BTNode*root){
        if(!root) return 0;
        int left = 1+max_levels(root->left);
        int right = 1+max_levels(root->right);
        return max(left, right);
    }
 
    void nodes_at_level_k(int k, BTNode* root, vector<int> &v){
        if (!root) return ;
        if(k==1) {
            v.push_back(root->val);  
            return;
        }
        nodes_at_level_k(k-1,root->left,v);
        nodes_at_level_k(k-1,root->right,v);
    }   
    vector<int> nodes_at_level_k(int k){
        vector <int> v={};
        if(k==0) return v;
        nodes_at_level_k(k,root,v);
        return v;
    }

    void LevelOrder(BTNode *root) {
        if(root == NULL) return;
        queue<BTNode*> Q;
        Q.push(root);  
        //while there is at least one discovered node
        while(!Q.empty()) {
            BTNode* BTNode = Q.front();
            Q.pop(); // removing the element at front
            cout<<root->val<<" ";
            if(root->left != NULL) Q.push(root->left);
            if(root->right != NULL) Q.push(root->right);
        }
    }
};
int main(){
    // BTree t1;
    // t1.insert(70);
    // t1.insert(120);
    // t1.insert(30);
    // t1.insert(50);
    // t1.insert(65);
    // t1.insert(40);
    // t1.insert(55);
    // t1.insert(10);
    // t1.insert(20);
    // t1.insert(3);
    // t1.insert(7);
    // t1.insert(0);
    // t1.generateTree();
    // t1.generateTree();
    // t1.delNode(30);
    // t1.generateTree();
    // int arr[5]={-10,-3,0,5,9};
    
    // cout<<t1.node_with_val_matched(30);
    // t1.node_with_val_matched(30);
    // t1.make_ascending();
    // BTree t2;
    // int arr[5]={-10,-3,0,5,9};
    // t2.sorted_array_to_bst(arr,5);
    BTree t;
    t.insert(-200);
    t.insert(-800);
    t.insert(-1000);
    t.insert(-600);
    t.insert(-100);
    t.insert(-150);
    t.insert(100);
    t.insert(0);
    t.insert(200);
    t.generateTree();
    // t.pos_tree();
    // vector<int> v={-100,100,0,200,-150};
    // t.equal_subtree(v);
    // t.max_node();
    vector <int> v=t.nodes_at_level_k(3);
    cout<<endl;
    for(int n:v){
        cout<<n<<" ";
    }
    return 0;
}