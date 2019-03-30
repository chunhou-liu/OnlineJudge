#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int countOfSubarrays(const vector<int> &nums, int k){
    int n=nums.size();
    int dp[n][n];
    int ans=0;
    for(int i=0;i<n;++i){
        dp[i][i]=nums[i];
        if(dp[i][i]>k){
            ++ans;
        }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=i+1;j<n;++j){
            dp[i][j]=max(dp[i][j-1], nums[j]);
            if(dp[i][j]>k)++ans;
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int n, k;cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << countOfSubarrays(nums, k) << endl;
    }
    return 0;
}