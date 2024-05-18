#include <iostream>
using namespace std;

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

int main(){
    int a = 4;
    int b = 5;
    cout << "a = " << a << " b = " << b << endl;
    int *pta = &a;
    int *ptb = &b;
    // we can either do this:
    swap(*pta,*ptb);
    // or this:
    // swap(&a,&b); 
    cout << "a = " << a << " b = " << b << endl;

    // if neither ways are followed then a and b will be passed as value to swap func just like py and 
    // updated values wont appear in main
    // return 0;
    // if neither ways are followed then a and b will be passed as value to swap func just like py and 
    // updated values wont appear in main
}