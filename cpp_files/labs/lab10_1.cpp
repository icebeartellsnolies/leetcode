#include <iostream>
using namespace std;
#define SEN 0

int count_nodes(const char *x, int i, const int &END) {
    if (i >= END || x[i] == SEN)
        return 0;
    return 1 + count_nodes(x, 2 * i, END) + count_nodes(x, 2 * i + 1, END); 
}
int search_index(const char *x, const int& END, char to_search,int i){
	if(i>=END) 
        return -1;
	if (x[i]==to_search) 
        return i;
	int left= search_index(x, END, to_search,i*2);
	if (left!=-1) 
        return left;
	return search_index(x, END, to_search,i*2+1);
}

char largest_element(const char *x, const int& END, int i) {
    if (i >= END || x[i] == SEN) return 0;
    char left = largest_element(x, END, i*2);
    char right = largest_element(x, END, i*2+1);
    return max(x[i],max(left, right));
}

int main(){
    char x[] = {SEN,'a','b','c','d','e','f',SEN, SEN, 'g','h',SEN,'i','j'};
    cout<<"number of nodes: ";
    cout<<count_nodes(x,1,14)<<endl;
    cout<<"the index of f is: ";
    cout<<search_index(x,14,'f',1)<<endl;
    cout<<"largest elment in the tree is: ";
    cout<<largest_element(x,14,1);
}