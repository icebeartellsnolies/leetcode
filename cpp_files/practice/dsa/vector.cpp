#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> v={1,2,3,4,5};
    vector <int> v2(2,0);
    for(int num:v2)
    cout<<num << " ";
    // cout<<v;
}