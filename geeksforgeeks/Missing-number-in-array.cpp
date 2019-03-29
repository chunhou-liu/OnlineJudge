#include <iostream>
#include <vector>
using namespace std;


int missingNumber(vector<int> &nums){
    vector<bool> helper(nums.size()+1, false);
    for(int i=0;i<nums.size();++i)
        helper[nums[i]-1]=true;
    for(int i=0;i<helper.size();++i)
        if(!helper[i])return i+1;
    return 0;
}


int main(){
    int T;cin>>T;
    for(int i=0;i<T;++i){
        int N;cin>>N;
        vector<int> nums(N-1);
        for(int i=0;i<N-1;++i)cin>>nums[i];
        cout << missingNumber(nums) << endl;
    }
}