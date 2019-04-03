#include <iostream>
#include <vector>
using namespace std;


int longestBitonicSubseq(vector<int> &nums){
    int n=nums.size();
    int dp1[n], dp2[n];
    dp1[0]=1;dp2[n-1]=1;
    for(int i=1;i<n;++i){
        dp1[i]=1;
        for(int j=0;j<i;++j)
            if(nums[j]<nums[i])dp1[i]=max(dp1[i], dp1[j]+1);
    }
    for(int i=n-2;i>=0;--i){
        dp2[i]=1;
        for(int j=i+1;j<n;++j)
            if(nums[j]<nums[i])dp2[i]=max(dp2[i], dp2[j]+1);
    }
    int ans=dp1[0]+dp2[0]-1;
    for(int i=1;i<n;++i)ans=max(ans, dp1[i]+dp2[i]-1);
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << longestBitonicSubseq(nums) << endl;
    }
    return 0;
}