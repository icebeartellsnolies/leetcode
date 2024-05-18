#include <iostream>
#include <cstdlib>
#include <ctime>

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
	BTree(){		root = NULL;	}
	BTNode* insert(int value, BTNode *temp){	
		if (!temp)	return new BTNode(value);
		int randomN = rand() % 2;
		if (randomN == 0) 		temp->left = insert(value, temp->left);
		else 					temp->right = insert(value, temp->right);
		return temp;
	}
	void insert(int value){		root = insert(value, root);	}
	void generateTree(BTNode *temp, int tabs = 0){
		if (!temp)	return;
		generateTree(temp->right, tabs + 1);
		for (int i = 0 ; i < tabs ; i++)	cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
	void generateTree(){		generateTree(root);	}
	void inorder(BTNode *temp){
		if (!temp)	return;
		inorder(temp->left);
		cout << temp -> val << ' ';
		inorder(temp->right);
	}
	void inorder(){	inorder(root);	}
	void preorder(BTNode *temp){
		if (!temp)	return;
		cout << temp -> val << ' ';
		preorder(temp->left);
		preorder(temp->right);
	}
	void preorder(){	preorder(root);	}
	int countNodes(BTNode *temp){
		if (!temp)		return 0;
		int countLeft = countNodes(temp->left);
		int countRight = countNodes(temp->right);
		return countLeft + countRight + 1;
	}
	int countNodes(){	return countNodes(root);	}	
	int height(BTNode *temp){
		if (!temp)	return 0;
		return max(height(temp->left), height(temp->right)) + 1;
	}
	int height(){	return height(root);	}

	int height_balanced(BTNode *root){
		if(!root) return 0;
		int left = height_balanced(root->left);
		int right = height_balanced(root->right);
		if (left==-1||right==-1)
			return -1;
		int h = abs(left-right);
		if (h>1)
			return -1;
		else 
			return max(left, right)+1;
	}
	bool is_height_balanced(){
		int h = height_balanced(root);
		if (h==-1)
			return false;
		return true;
	}
	int sum_nodes(BTNode*root){
		if(!root) return 0;
		int sum = root->val;
		sum+=sum_nodes(root->left)+sum_nodes(root->right);
		return sum;
	}
	int max_node(BTNode*root,int max_val){
		if(!root)
			return max_val;
		max_val=max(max_val,root->val);
		int l_max=max_node(root->left,max_val);
		int r_max=max_node(root->right,max_val);
		return max(l_max,r_max);
	}
	int max_node(){
		return max_node(root,root->val);
	}
	// int findTilt(BTNode* root) {
    //     if(!root) return 0;
    //     int sum = 
    //     return root->val+sum_nodes(root->left)+sum_nodes(root->right);
    // }
	// void findTilt(){
	// 	findTilt(root);
	// }
	// leetcode 257
};
int main(){
	srand(time(0));
	BTree tree;
	for (int i=0;i<15;i++)
		tree.insert(rand()%900+100);
    tree.generateTree();
	// cout<< tree.is_height_balanced();
	// tree.findTilt();
	cout<<endl<<endl<<endl;

	cout<<tree.max_node()<<endl;
	return 0;
}