#include <iostream>
#include <vector>
using namespace std;


int maxProfit(vector<int> &nums, int k){
    int n=nums.size();
    int dp[n][k+1];
    int ans=0;
    for(int i=0;i<n;++i)dp[i][0]=0;
    for(int i=0;i<=k;++i)dp[0][i]=0;
    for(int i=1;i<n;++i){
        for(int j=1;j<=k;++j){
            dp[i][j]=dp[i-1][j];
            for(int t=0;t<i;++t)
                if(nums[t]<nums[i])dp[i][j]=max(dp[i][j], (t>0?dp[t-1][j-1]:0)+nums[i]-nums[t]);
            ans=max(ans, dp[i][j]);
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int k, n;cin>>k>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << maxProfit(nums, k) << endl;
    }
}