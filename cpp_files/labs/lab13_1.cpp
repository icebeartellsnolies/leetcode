#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int hash_func(vector <int>v){
    vector<int> hash(2000,0);
    for(int n:v){
        hash[n+1000]++;
    }
    for(int n:hash){
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<2000;i++){
        if(hash[i]==1){
            return i-1000;
        }
    }
    return -1;
}
int main(){
    
    vector<int> ints;
    for(int i=0; i<1000;i++){
        ints.push_back((rand()%2000)-1000);
    }
    
    for(int i=0;i<1000;i++){
        cout<<ints[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<hash_func(ints);
    return 0;
}
