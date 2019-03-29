#include <iostream>
#include <vector>
using namespace std;


pair<int, int> subarraySum(vector<int> &nums, int target){
    if(nums[0]==target)return pair<int,int>(1,1);
    for(int i=1;i<nums.size();++i){
        nums[i]+=nums[i-1];
        if(nums[i]==target)return pair<int,int>(1, i+1);
        for(int j=i;j>0;--j){
            if(nums[i]-nums[j-1]==target)return pair<int,int>(j+1, i+1);
            if(nums[i]-nums[j-1]>target)break;
        }
    }
    return pair<int,int>(-1,-1);
}


int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n, s;
        cin>>n>>s;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        pair<int,int> ans = subarraySum(nums, s);
        if(ans.first==-1)cout << -1 << endl;
        else cout << ans.first << ' ' << ans.second << endl;
    }
}