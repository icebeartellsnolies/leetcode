#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
class players{
    public:
    int playerno;
    int matches;
    float average;
    int totalruns;
    int notout;
    int highestscore,four,sixes;
    
    players(int player,int matche,int averag,int total,int no,int high,int four,int six){
        this->playerno=player;
        this->matches=matche;
        this->average=averag;
        this->totalruns=total;
        this->notout=no;
        this->highestscore=high;
        this->four=four;
        this->sixes=six;

    }
    void print(){
        cout<<"player no"<<playerno;
        cout<<endl<<"matches "<<matches;
        cout<<endl<<"Average: "<<average;
        cout<<endl<<"Total runs"<<totalruns;
        cout<<endl<<"not out: "<<notout;
        cout<<endl<<"Highest score: "<<highestscore;
        cout<<endl<<"FOur: "<<four;
        cout<<endl<<"Sixes: "<<sixes<<endl;
    }

};
class AVLTree{
	struct AVLNode{
		int val, height,key;
		AVLNode *left, *right;
		AVLNode(int val,int key, AVLNode *left=NULL, AVLNode *right=NULL){
			this->val = val;
            this->key=key;
			this->left = left;
			this->right = right;
			this->height = 1;

		}
	};
	AVLNode *root;
public:
	AVLTree(){	root = NULL;	}
	AVLNode* leftRotation(AVLNode* temp){
		AVLNode* temp_right = temp->right;
		temp->right	= temp_right->left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_right->left = temp;
		temp = temp_right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
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
	AVLNode* insert(int d,int key, AVLNode *temp){	
		if (temp==NULL)	return new AVLNode(d,key);
		if (temp->val>d) 			temp->left = insert(d,key, temp->left);
		else if (temp->val<d) 		temp->right = insert(d,key, temp->right);
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	void insert(int d,int key){	
		root = insert(d,key, root);
	}
	AVLNode* findLeftMost(AVLNode *t){
		if (t->left == NULL)	return t;
		return findLeftMost(t->left);
	}
	AVLNode* remove(int d, AVLNode *temp, bool& isDeleted ){	
		if (temp == NULL)			return NULL;
		if (temp->val > d) 			temp->left = remove(d, temp->left, isDeleted);
		else if (temp->val < d) 	temp->right = remove(d, temp->right, isDeleted);
		else{	//this is the node to be deleted
			if (!temp->left && !temp->right){
				delete temp;	//delete leaf node and return null
				isDeleted = true;
				return NULL;
			}
			else if (temp->left == NULL && temp->right != NULL){
				AVLNode *tempR = temp->right;	//Before deletion save right child
				delete temp;					//delete current node
				isDeleted = true;
				return tempR;				//return right child to connect with grand parent
			}
			else if (temp->right == NULL){
				AVLNode *tempL = temp->left;		//Before deletion save left child
				delete temp;					//delete current node
				isDeleted = true;
				return tempL;				//return left child to connect with grand parent
			}
			else{	//node has both left and right child nodes
				AVLNode *toBeReplaced = 	findLeftMost(temp->right);//you can either find left most in right sub tree or right most in left sub tree
				temp->val = toBeReplaced->val;
				temp->right = remove(temp->val, temp->right, isDeleted);//delete the left most node having same val but single or zero child node being left most
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
     AVLNode*  search(AVLNode *root, int value){
        if(!root) return NULL;
        if (root->val==value)
            return root;
        if (value>root->val)
            return search(root->right, value);
        else
            return search(root->left, value);
    }
    int  search(int value){
       AVLNode* a=search (root, value);
       if (!a) return -1;
       return a->key;

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
	
};

using namespace std;
int main(){
    vector<players>player1;
    for (int i=0;i<10000;i++){
        int player=i+1;
        int matches=rand()%200+1;
        float average=rand()%60+5;
        int total=rand()%200;
        int notout=rand()%20;
        int high=rand()%200+1;
        
        int four=rand()%10;
        
        int six=rand()%10;
        players p1(player,matches,average,total,notout,high,four,six);
        player1.push_back(p1);
    }
        AVLTree tree1;
        AVLTree tree2;
        AVLTree tree3;
        AVLTree tree4;
        for (int i=0;i<10000;i++){
            tree1.insert(player1[i].totalruns,player1[i].playerno);
            tree2.insert(player1[i].average,player1[i].playerno);
            tree3.insert(player1[i].four,player1[i].playerno);
            tree4.insert(player1[i].sixes,player1[i].playerno);
        }
        clock_t start = std::clock();
        for (int i=0 ;i<10;i++){
            int tosearchruns=rand()%200+1;
            for (int i=0;i<10000;i++){
                
                if (player1[i].totalruns==tosearchruns){
                    cout<<"player with "<<tosearchruns<<" runs: "<<endl;
                    player1[i].print(); 
                    break;  
                }
        }
     int six=rand()%10;
            for (int i=0;i<10000;i++){
              
             if (player1[i].sixes==six){
                cout<<"Player with "<<six<<"Number of sixes:"<<endl;
                player1[i].print();
                break;
        }
        }
        int four=rand()%10;
        for (int i=0;i<10000;i++){

        if (player1[i].four==four)
             {
               cout<<"player who has "<<four<<"number of fours: "<<endl;

                player1[i].print();
                break;
             }    
        }
        int tosearchavg=rand()%200;
            for (int i=0;i<10000;i++){
               
                if (player1[i].average==tosearchavg){
                     cout<<"Player no of given average:"<<endl;
                player1[i].print();
                break;
                }
        }
         
   
        }
        clock_t end = std::clock();
    double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken to search through vector: " << duration << " milliseconds\n";
        
clock_t start1 = std::clock();
        for (int i=0;i<10;i++){
             int tosearchruns=rand()%200+1;
            int tosearchavg=rand()%60+5;
            
            int four=rand()%10+0;
           
            int six=rand()%10;
            cout<<"Key of required runs: "<<tree1.search(tosearchruns)<<endl;
            cout<<"Key of required average: "<<tree2.search(tosearchavg)<<endl;
            cout<<"Key of required four: "<<tree3.search(four)<<endl;
            cout<<"Key of required six: "<<tree4.search(six)<<endl;


        }
         clock_t end1 = std::clock();
    double duration1 = 1000.0 * (end1 - start1) / CLOCKS_PER_SEC;
    cout << "\nTime taken to search through tree: " << duration1 << " milliseconds\n";
        return 0;
}