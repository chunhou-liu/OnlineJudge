#include <iostream>
#include <vector>
using namespace std;


int maxIncreasingSubseq(vector<int> &nums){
    int n=nums.size();
    int dp[n], ans=nums[0];
    dp[0]=nums[0];
    for(int i=1;i<nums.size();++i){
        dp[i]=nums[i];
        for(int j=0;j<i;++j)
            if(nums[j]<nums[i])dp[i]=max(dp[i], dp[j]+nums[i]);
        ans=max(ans, dp[i]);
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << maxIncreasingSubseq(nums) << endl;
    }
    return 0;
}