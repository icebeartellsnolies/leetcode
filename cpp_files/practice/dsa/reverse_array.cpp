#include<iostream>
#include<vector>
using namespace std;

void reverselist(vector<int> &nums,int l,int r) {
    if (l>=r) return ;
    swap(nums[l],nums[r]);
    l++;
    r--;
    reverselist(nums,l,r);
      
}
int main(){
    vector<int> v={1,2,3,4,5};
    reverselist(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}