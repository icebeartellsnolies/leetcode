#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

struct players 
{
    int player_num,matches, total_runs, noy_out, highest_score, fours, sixes;
    float average;
    players(int player_num,int matches, int total_runs, int noy_out, int highest_score, int fours, int sixes,float average){
        this->player_num=player_num;
        this->matches=matches;
        this->total_runs=total_runs;
        this->noy_out=noy_out;
        this->highest_score=highest_score;
        this->fours=fours;
        this->sixes=sixes;
        this->average=average;
    }
};
int max(const int a, const int b){
	if (a < b)	return b;
	return a;
}
class AVLTree{
	struct AVLNode{
		int val, height;
		AVLNode *left, *right;
        int index;

		AVLNode(int val, AVLNode *left=NULL, AVLNode *right=NULL){
			this->val = val;
			this->left = left;
			this->right = right;
			this->height = 1;
            this->index;
		}
	};
	AVLNode *root;
public:
	AVLTree(){	root = NULL;	}
	AVLNode* leftRotation(AVLNode* temp){

		AVLNode* t = temp->right;
		temp->right	= t->left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		t->left = temp;
		temp = t; //new temp
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;//h of new temp
		return temp;
	}
	AVLNode* rightRotation(AVLNode* temp){
		AVLNode* temp_left = temp->left;
		temp->left	= temp_left->right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_left->right = temp;
		temp = temp_left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;
	}
	int getHeight(AVLNode* t) const{
		if (!t)	return 0;
		return t->height;
	}

	int getHeight() const{
		if (!root)	return 0;
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		return max(lh, rh) + 1;
	}

	AVLNode* doRightRotation(AVLNode* temp){
		int balance = getHeight(temp->left->left) - getHeight(temp->left->right);
		if (balance < 0) 	temp->left = leftRotation(temp->left);
		temp = rightRotation(temp);
		return temp;
	}
	AVLNode* doLeftRotation(AVLNode* temp){
		int balance = getHeight(temp->right->left) - getHeight(temp->right->right);
		if (balance > 0) 	temp->right = rightRotation(temp->right);
		temp = leftRotation(temp);
		return temp;
	}
	AVLNode* doRotation(AVLNode* temp){
		int balance = getHeight(temp->left) - getHeight(temp->right);
		if (balance > 1)			temp = doRightRotation(temp);
		else if (balance < -1)		temp = doLeftRotation(temp);
		return temp;		
	}
	AVLNode* insert(int d, AVLNode *temp, int index){	
		if (temp==NULL)	//!root
			return new AVLNode(d);
		int val = temp->val;
		if (d<temp->val) 			
			temp->left = insert(d, temp->left, index);
		else if (d>temp->val) 		
			temp->right = insert(d, temp->right, index);
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	void insert(int d, int index){	
		root = insert(d, root, index);
	}
	AVLNode* findLeftMost(AVLNode *t){
		if (t->left == NULL)	return t;
		return findLeftMost(t->left);
	}
	AVLNode* remove(int d, AVLNode *temp, bool& isDeleted ){	
		if (temp == NULL)			return NULL;
		if (temp->val > d) 			
			temp->left = remove(d, temp->left, isDeleted);
		else if (temp->val < d) 	
			temp->right = remove(d, temp->right, isDeleted);
		//this is the node to be deleted
		else{	
			if (!temp->left && !temp->right){
				delete temp;	//delete leaf node and return null
				isDeleted = true;
				return NULL;
			}
			else if (temp->left == NULL && temp->right != NULL){
				AVLNode *tempR = temp->right;	//Before deletion save right child
				delete temp;					//delete current node
				isDeleted = true;
				return tempR;			//return right child to connect with grand parent
			}
			else if (temp->right == NULL){
				AVLNode *tempL = temp->left;		//Before deletion save left child
				delete temp;					//delete current node
				isDeleted = true;
				return tempL;				//return left child to connect with grand parent
			}
            //node has both left and right child nodes
			else{	
            //you can either find left most in right sub tree or right most in left sub tree
				AVLNode *toBeReplaced = 	findLeftMost(temp->right);
				temp->val = toBeReplaced->val;
            //delete the left most node having same val but single or zero child node being left most		
				temp->right = remove(temp->val, temp->right, isDeleted);
            }
		}
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	bool remove(int d){	
		bool isDeleted = false;
		root = remove(d, root, isDeleted);
		return isDeleted;
	}
	void inorder(AVLNode* t){
		if (t!=NULL){
			inorder(t->left);
			cout << t->val << ' ';
			inorder(t->right);
		}
	}
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	void preorder(AVLNode* t){
		if (t!=NULL){
			cout << t->val << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder(){
		preorder(root);
		cout << '\n';
	}
	void removeNodes(AVLNode* t){
		if (t!=NULL){
			removeNodes(t->left);
			removeNodes(t->right);
			delete t;
		}
	}
	~AVLTree(){
		removeNodes(root);
	}
	void generateTree(AVLNode *temp, int tabs){
		if (!temp)	return;
		generateTree(temp->right, tabs + 1);
		for (int i = 0 ; i < tabs ; i++)	cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
	void generateTree(){
		generateTree(root, 0);
	}		
    AVLNode* search(AVLNode *root, int value){
        if(!root) return NULL;
        if (root->val==value)
            return root;
        if (value>root->val)
            return search(root->right, value);
        else
            return search(root->left, value);
    }
    int search(int value){
        AVLNode *a =search (root, value);
		if(!a) return -1;
		return a->index;
    }
	// AVLNode* createminheightavl(int height,AVLNode* temp,int n){
		
	// 	if (height==0)
	// 	return NULL;
		
	// 	int val=rand()%90+10;
	// 	AVLNode* root=new AVLNode(val);
	// 	if(height==1)
	// 	return root;
	// root->left=createminheightavl(height-1,root,n);
	// root->right=createminheightavl(height-2,root,n);
	// return root;
	// }
	// void createminheightavl(int height){
	// 	root=createminheightavl(height,root,1);

	// }
    int min_no_of_nodes(int h){
        if (h==1 || h==2)
            return h;
        return min_no_of_nodes(h-1)+min_no_of_nodes(h-2)+1;
    }
};
// void time(){
//     clock_t start = std::clock();
//     for (int i = 1; i <= 100000; i++)
//         std::cout << i << " ";
//     clock_t end = std::clock();
//     double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
//     cout << "\nTime taken to print numbers: " << duration << " milliseconds\n";  
// }
int main(){
    vector<players>v;
    for(int i=0;i<10;i++){
        
        int player=i+1;
        int matches=rand()%200+1;
        float avg=rand()%60+5;
        int total_runs=matches*avg;
        int not_out= rand()%100;
        int highest_score=rand()%200+avg;
        int fours=rand()%((total_runs/4));
        int sixes=rand()%(((total_runs-fours)/6));
        players p1(player,matches,total_runs,not_out,highest_score,fours,sixes,avg);
        v.push_back(p1);
    }
	// AVLTree *runsss;
	// AVLTree *avg;
	// AVLTree *fours;
	// AVLTree *sixes;
	// AVLTree *runsss = new AVLTree();
	// AVLTree *avg = new AVLTree();
	// AVLTree *fours = new AVLTree();
	// AVLTree *sixes = new AVLTree();
	AVLTree runsss;
	AVLTree avg;
	AVLTree fours ;
	AVLTree sixes; 
	for(int i=0; i<10;i++){
		runsss.insert(v[i].total_runs,i+1);
		avg.insert(v[i].average,i+1);
		fours.insert(v[i].fours,i+1);
		sixes.insert(v[i].sixes,i+1);
	}
	clock_t start = std::clock();
	for(int i=0; i<10;i++){
		int random_matches=rand()%200+1;
		float random_avg=rand()%60+5;
		int random_total_runs=random_matches*random_avg;
		int random_fours=rand()%((random_total_runs/4));
        int random_sixes=rand()%(((random_total_runs-random_fours)/6));
		
		for(int i=0;i<10;i++){
			if (v[i].average==random_avg){
				cout<<i;
			}
			else if (v[i].total_runs==random_total_runs){
				cout<<i;
			}
			else if (v[i].fours==random_fours){
				cout<<i;
			}
			else if (v[i].sixes==random_sixes){
				cout<<i;
			}
		}
	}
	clock_t end = std::clock();
	double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	cout << "\nTime taken to print numbers: " << duration << " milliseconds\n"; 
	cout<<endl; 
	clock_t s = std::clock();
	
	for(int i=0;i<10;i++){

		int a= runsss.search(v[i].total_runs);
		if (a==INT_MIN)
			cout<<runsss.search(v[i].total_runs);
		int b = avg.search(v[i].average);
		if (b!=INT_MIN)
			cout<<avg.search(v[i].average);
		int c=fours.search(v[i].fours);
		if (c!=INT_MIN)
			cout<<fours.search(v[i].fours);
		int d= sixes.search(v[i].sixes);
		if (d!=INT_MIN)
			cout<<sixes.search(v[i].sixes);
	}
	clock_t e = std::clock();
	double d = 1000.0 * (e - s) / CLOCKS_PER_SEC;
	cout << "\nTime taken to print numbers: " << d << " milliseconds\n";  
	}
