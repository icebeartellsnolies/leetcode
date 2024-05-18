#include <iostream>
using namespace std;

int main(){

    // int a =20;
    // int *pta = &a;
    // cout << "this is pta " << pta << endl;
    // cout << "this is &a " << &a << endl; 
    // cout << "this is *pta " << *pta << endl;

    int arr[4] = {1,2,3,4};
    // cout << *arr+1 ;

    // int *ptr = arr;
    // for (int i = 0; i<4; i++){
    //     cout << *ptr<< endl;
    //     ptr++; 
    // }

    // for (int i = 0; i<4; i++){
    //     cout << *arr+i<< endl; 
    // }

    // double pointers
    int a = 10;
    int *q = &a;
    int **p = &q;
    cout << "first pointer val is " << *q << endl;
    cout << "second pointer val is " << *p;  //gives the address of q

}