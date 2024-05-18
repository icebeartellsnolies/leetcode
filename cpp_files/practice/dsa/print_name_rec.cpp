#include <iostream>
using namespace std;

void print(char x[], int i, int n){
    if (i>=n) return;
    print(x,i+1,n);
    cout << x[i]<<" ";
    print(x, i+2, n);
}

int main(){
    char c[5] = {'p', 'a', 'k', 'i', 's'};
    print(c,0,5);
    return 0;
}