#include <vector>
using namespace std;


class NumArray {
    vector<int> nums, sums;
public:
    NumArray(vector<int>& nums) : nums(nums), sums(nums){
        for(int i=1;i<sums.size();++i)sums[i]+=sums[i-1];
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        for(int j=i;j<sums.size();++j)sums[j]+=diff;
    }
    
    int sumRange(int i, int j) {
        if(i==0)return sums[j];
        return sums[j]-sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */