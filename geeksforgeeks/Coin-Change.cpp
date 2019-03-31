#include <iostream>
#include <vector>
using namespace std;


int coinChange(vector<int> &nums, int k){
    int n=nums.size();
    int dp[n+1][k+1];
    for(int i=0;i<=k;++i)dp[0][i]=0;
    for(int i=0;i<=n;++i)dp[i][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            dp[i][j]=0;
            for(int t=0;t*nums[i-1]<=j;++t)dp[i][j]+=dp[i-1][j-t*nums[i-1]];
        }
    }
    return dp[n][k];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n, k;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cin>>k;
        cout << coinChange(nums, k) << endl;
    }
}