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
		for (int i = 0 ; i < tabs ; i++)	
			cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
	void generateTree(){		generateTree(root);	}
	
    bool isSameTree(BTNode *temp1,BTNode *temp2){
        if (!temp1 && !temp2) return true;
		if(!temp1 || !temp2 || temp1->val != temp2->val  ) return false;
		return isSameTree(temp1->left, temp2->left) && isSameTree(temp1->right, temp2->right);
    }
	bool isSameTree(BTree *t2){		
		return isSameTree(this->root, t2->root);	
	}
};
int main(){
	
	srand(time(0));
    BTree t1, t2;

    vector<int> values;
    for (int i = 0; i < 15; i++) {
        values.push_back(rand() % 900 + 100);
    }
    for (int value : values) {
        t1.insert(value);
        t2.insert(value);
    }
	t1.generateTree();
	cout<<endl<<endl;
	t2.generateTree();
	cout<<t1.isSameTree(&t2);
	return 0;
}