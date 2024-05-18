#include <iostream>
#include <tuple>
using namespace std;

#define SEN 0

void preOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	cout << x[i] << ' '; //parent
	preOrder(x, i * 2, 14);
	// preOrder(x, i * 2, 14):gives the left node
	preOrder(x, i * 2 + 1, 14);
	// preOrder(x, i * 2 + 1, 14):gives the right node
}

void inOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	inOrder(x, i * 2, 14);
	cout << x[i] << ' ';
	inOrder(x, i * 2 + 1, 14);
}

void postOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	postOrder(x, i * 2, 14);
	postOrder(x, i * 2 + 1, 14);
	cout << x[i] << ' ';
}

void level_order(const char *x, int i, const int& END){
	if (i>=END ) return;
	if (x[i]!=SEN)
		cout<< x[i]<<" ";
	level_order(x,i+1, END);
}
int count_nodes(const char *x, int i, const int &END) {
    if (i >= END || x[i] == SEN)
        return 0;
    return 1 + count_nodes(x, 2 * i, END) + count_nodes(x, 2 * i + 1, END); 
}

int search_index(const char *x, const int& END, char to_search,int i){
	if(i>=END) return -1;
	if (x[i]==to_search) return i;
	int left= search_index(x, END, to_search,i*2);
	if (left!=-1) return left;
	return search_index(x, END, to_search,i*2+1);
}

int search_index(const char *x, const int& END, char to_search){
	return search_index(x, END, to_search,1);
}
char largest_element_sub(const char *x, const int& END, int i) {
    if (i >= END || x[i] == SEN) return 0;
    char left = largest_element_sub(x, END, i * 2);
    char right = largest_element_sub(x, END, i * 2 + 1);
    return max(left, right);
}
char largest_element(const char *x, const int& END, int i){
	return max(largest_element_sub(x,END,1), x[1]);
}
int count_levels(char *x, int i, int end,bool left){
	if (i>=end) return 0;
	int level=0;
	if (i<end)
		level=1;
	if (left)
		level+=count_levels(x,i*2,end, left);
	else
		level+=count_levels(x,i*2+1,end, left);
	return level;
}
int countoccurrences(char *x, int i, int end, char to_search) {
    if (i >= end) return 0; 
    int count = 0;
    if (x[i] == to_search)
        count = 1;
    count += countoccurrences(x, 2 * i , end, to_search); 
    count += countoccurrences(x, 2 * i + 1, end, to_search);
    return count;
}
bool is_bst(const char *x, const int& END,int i){
	if (i>=END) return left && right;
	else{
		bool left = (x[i*2]<x[i] && is_bst(x, i*2, END));
		bool right = (x[i*2+1]>x[i] && is_bst(x, i*2+1, END));
	}
	return left && right;
}
tuple<int, int>count_left_right(char *x, int END, int i){
	return make_tuple(count_nodes(x,i*2,END),count_nodes(x,i*2+1,END));
}
void skewness(char *x, int END, int i) {
    if (i >= END || x[i] == SEN)
        return;
    auto [left_c, right_c] = count_left_right(x, END, i);
    cout << x[i] << ": ";
    if (left_c > right_c)
        cout << "left skewed";
    else if (left_c < right_c)
        cout << "right skewed";
    else
        cout << "balanced";
    cout << endl;

    skewness(x, END, 2 * i);
    skewness(x, END, 2 * i + 1);
}
void print_height(char *x, int END, int i){
	if (i>=END||x[i]==SEN)
		return;
	cout<<x[i]<<' '<<"has height: ";
	int h=max(count_levels(x,i,END,true),count_levels(x,i,END,false));
	cout<<h-1<<endl;
	print_height(x,END,i*2);
	print_height(x,END,i*2+1);
}
bool are_mirrors(char* subtree, int END, int left, int right) {
    if (left >= END || right >= END) return true; 
    if (subtree[left] == SEN && subtree[right] == SEN) return true; 
    if (subtree[left] == SEN || subtree[right] == SEN) return false;
    if (subtree[left] != subtree[right]) return false; 

    return are_mirrors(subtree, END, left * 2, right * 2 + 1) &&
           are_mirrors(subtree, END, left * 2 + 1, right * 2);
}


bool is_mirror(char* x, int END, int i) {
    if (i > END || x[i] == SEN) return true; 
	bool left= is_mirror(x, END, i * 2);
    bool right = is_mirror(x, END, i * 2 + 1);
   
    bool parent_mirror = are_mirrors(x, END, i * 2, i * 2 + 1);
	bool mirror = parent_mirror && left && right;

    cout << x[i] << " ";
    if (mirror)
        cout << "has a mirror subtree";
    else
        cout << "doesn't have a mirror subtree";
    cout << endl;

    return mirror;
}
int sub_tree_sum(int x[], int end, int i){
	if(i>=end) 
		return 0;
	int left_sum = sub_tree_sum(x, end, i * 2);     
    int right_sum = sub_tree_sum(x, end, i * 2 + 1); 
    return x[i] + left_sum + right_sum;
}
int k_sum(int x[], int end, int i, int k){
	if(i>=end) return -1;
	if (x[i]!=SEN){
		int left = sub_tree_sum(x,end,i*2);
		int right = sub_tree_sum(x,end,i*2+1);
		if (left+right==k)
			return i;
		if(left == k)
			return i*2;
		if (right==k)
			return i*2+1;
	}
	int left = sub_tree_sum(x,end,i*2);
	int right = sub_tree_sum(x,end,i*2+1);
	if (left!=-1) return left;
	return right;
}
void print_left_side(int x[], int end, int i){
	if (i>=end) return;
	if (x[i]!=SEN){
		cout<<x[i]<<" ";
		print_left_side(x,end,i*2);
	}
	else{
		print_left_side(x,end,i+1);
	}
}
bool ismirror(char *y,int i,int j,int end){
	if (i>end || j>end) return true;
	if (y[i]==SEN && y[j]==SEN ) return true;
	if (y[i]!=SEN && y[j]!=SEN) {
		if (y[i]==y[j])
			return (ismirror(y,i*2,j*2+1,end) && ismirror(y,i*2+1,j*2,end));
		else
			return false;
	}
	else
		return false;
}
bool issymetric(char *y ,int i,int end){
	return ismirror(y,i*2,i*2+1,end);
}
bool ismirror_bilal(const char *x, int i, const int& END){
    if (i >= END || x[i] == SEN ){
        return true;
    }
    int left = i*2;
    int right = (i*2)+1;
    return ismirror_bilal(x,left,END) && ismirror_bilal(x,right,END) && x[left] == x[right];
}
// int print_left_side(int x[], int end, int i){
// 	if (i>=end) return x[1];
// 	int left = print_left_side(x,end,i*2);
// 	if (left!=SEN){
// 		print_left_side(x,end,i*2);
// 		return left;
// 	}
// 	else{
// 		return print_left_side(x,end,i+1);
// 	}
// }
int main(){
	char x[] = {SEN,'a','b','c','d','e','f',SEN, SEN, 'g','h',SEN,'i','j'};
	// cout << "Pre Order: ";
	// preOrder(x, 1, 14);
	// cout << "\nIn Order: ";
	// inOrder(x, 1, 14);
	// cout << "\nlevel Order: ";
	// level_order(x, 1, 14);
	// cout << "\nPost Order: ";
	// postOrder(x, 1, 14);
    // cout<<endl;
    // cout<<count_nodes(x,1,14);
	// cout<<endl;
	// cout<<search_index(x,14,'c');
	// cout<<endl;
	// cout<<largest_element(x,14,1);
	char y[] = {SEN,2,1,3,SEN,SEN, SEN, 5};
	// cout<<is_bst(y, 8, 1);
	// char z[] = {SEN,2,1,3,SEN,SEN, SEN, 2,5};
	// cout<<countoccurrences(z,1,9,2);
	// skewness(x,14,1);
	// print_height(x,14,1);
	// char m[]={1, 2, 3,4, 5, 6, 4,SEN, SEN, SEN, SEN, 7, 8, 8, 7 };
	// cout<<sub_tree_sum(m,15,1);
	// int n[8]={SEN, 5, 3, 7, 1, 4, SEN, 2};
	// cout<<k_sum(n,8,1,5);
	// is_mirror(y,8,1);
	char mirror[10] = {SEN,'a','b','b','d','e','e', 'd','h','i'};
	char mirror2[8] = {SEN,'a','b','c','d','e','e', 'd'};
	// is_mirror(mirror, 10,1);
	// cout<<ismirror_bilal(mirror,1,8);
	// int r[12]={SEN,1, 2, 3, SEN, SEN, 4, SEN, SEN, 5, SEN, SEN};
	// print_left_side(r,12,1);
	
	return 0;
}
