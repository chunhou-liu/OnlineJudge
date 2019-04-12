#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int pairCount(vector<int> &nums, int k){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 0);
    int ans = 0;
    for(int i=1;i<n;++i){
        dp[i] = dp[i-1];
        for(int j=i-1;j>=0;--j){
            if(abs(nums[i]-nums[j])>=k)break;
            dp[i]=max(dp[i], nums[i]+nums[j]+(j==0?0:dp[j-1]));
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        int k;cin>>k;
        cout << pairCount(nums, k) << endl;
    }
    return 0;
}