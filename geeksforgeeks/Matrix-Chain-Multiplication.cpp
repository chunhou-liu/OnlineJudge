#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int matrixChainMultiplication(vector<int> &nums){
    int n=nums.size()-1; // n matrix
    int dp[n][n]; //dp[i][j] : minimum operations to multiply from ith to jth matrix
    for(int i=0;i<n;++i)dp[i][i]=0;
    for(int i=0;i<n-1;++i)dp[i][i+1]=nums[i]*nums[i+1]*nums[i+2];
    for(int i=n-1;i>=0;--i){
        for(int j=i+2;j<n;++j){
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;++k)dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+nums[i]*nums[k+1]*nums[j+1]);
        }
    }
    return dp[0][n-1];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << matrixChainMultiplication(nums) << endl;
    }
    return 0;
}