#include <iostream>
#include <vector>
using namespace std;

int maxAscendingSum(vector<int> nums) {
    int l = 0;
    int sum = nums[l];
    int max_sum=sum;
    for (int r=1;r<nums.size();r++){
        if(nums[r]>nums[r-1]){
            sum+=nums[r];
        }
        else{
            l=r;
            sum=nums[l];
            max_sum=max(sum, max_sum);
        }
    }
    return max_sum;
}
int main(){
    vector<int> v={12,17,15,13,10,11,12};
    cout<<maxAscendingSum(v);
}