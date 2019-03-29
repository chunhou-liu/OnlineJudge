#include <iostream>
#include <vector>
using namespace std;


int kadane(vector<int> &nums){
    int cursum=nums[0], maxsum=nums[0];
    for(int i=1;i<nums.size();++i){
        cursum=max(nums[i], cursum+nums[i]);
        maxsum=max(maxsum, cursum);
    }
    return maxsum;
}


int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << kadane(nums) << endl;
    }
}