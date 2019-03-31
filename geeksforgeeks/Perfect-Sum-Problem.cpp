#include <iostream>
#include <vector>
using namespace std;


int perfectSum(vector<int> &nums, int sum){
    int n=nums.size();
    int dp[sum+1];
    for(int i=0;i<=sum;++i)dp[i]=0;
    dp[0]=1;
    for(int i=0;i<n;++i)
        for(int j=sum;j>0;--j){
            if(nums[i]<=j)dp[j]+=dp[j-nums[i]];
        }
    return dp[sum];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n, sum;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cin>>sum;
        cout << perfectSum(nums, sum) << endl;
    }
    return 0;
}