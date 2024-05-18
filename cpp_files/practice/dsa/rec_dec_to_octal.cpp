#include<iostream>
using namespace std;
void dec_to_octal(int n){
    if (n>0){
        if (n>=8){
            cout << n/8;
            n=n%8;
            }
        else{
            cout << n ;
            return;
        }
    }
    dec_to_octal(n);
}

int main(){
    dec_to_octal(50);
}