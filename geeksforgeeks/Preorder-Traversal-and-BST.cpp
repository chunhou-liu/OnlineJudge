#include <vector>
#include <iostream>
using namespace std;


bool isBST(vector<int> &pre, int low, int high){
    if(low>high)return true;
    int pivot=pre[low], it=low+1, left, right;
    for(;it<=high && pre[it]<=pivot;++it);
    left=it-1;
    for(;it<=high && pre[it]>pivot;++it);
    if(it<=high)return false;
    return isBST(pre, low+1, left) && isBST(pre, left+1, high);
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << (isBST(nums, 0, n-1)?1:0) << endl;
    }
    return 0;
}