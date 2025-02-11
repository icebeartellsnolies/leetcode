#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int,int> dict;
    for (int i:nums){
        nums[i]+=1;
        if (nums[i]>nums.size()/2)
            return i;
    }
    return 0;
}
int main(){
    // vector<int>v={3,2,3};
    vector<int>v={1};
    cout<<majorityElement(v);
    return 0;
}