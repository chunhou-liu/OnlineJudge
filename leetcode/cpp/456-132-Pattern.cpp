#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3)return false;
        vector<int> min_values(nums.size(), nums[0]);
        int cur_min = nums[0];
        for(size_t i=1;i!=nums.size();++i){
            min_values[i] = min(min_values[i-1], nums[i]);
        }
        for(size_t i=1;i<nums.size();++i)
            for(size_t j=i+1;j<nums.size();++j)
                if(min_values[i]<nums[j] && nums[i]>nums[j])return true;
        return false;
    }
};