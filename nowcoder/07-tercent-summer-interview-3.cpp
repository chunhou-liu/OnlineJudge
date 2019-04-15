#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int minDiffCount(const vector<int> &nums){
    // nums asc sorted
    // find minimum difference
    int minDiff = nums[1]-nums[0];
    for(int i=2;i<nums.size();++i)
        minDiff = min(minDiff, nums[i]-nums[i-1]);
    int count = 0;
    for(int i=1;i<nums.size();++i){
        for(int j=i-1;j>=0 && nums[i]-nums[j]==minDiff;--j)++count;
    }
    return count;
}


int maxDiffCount(const vector<int> &nums){
    // nums asc sorted
    // find maximum difference
    int maxDiff = nums.back() - nums.front();
    // count
    int count = 0;
    for(int i=nums.size()-1;i>=0 && nums[i]==nums.back();--i){
        for(int j=0;j<nums.size() && nums[j]==nums.front();++j)++count;
    }
    return count;
}


int main(){
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        sort(nums.begin(), nums.end());
        cout << minDiffCount(nums) << ' ' << maxDiffCount(nums) << endl;
    }
    return 0;
}