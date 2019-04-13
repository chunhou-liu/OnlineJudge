#include <vector>
#include <iostream>
using namespace std;


bool isBST(vector<int> &inorder){
    for(int i=1;i<inorder.size();++i)
        if(inorder[i]<=inorder[i-1])return false;
    return true;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)cin>>nums[i];
        cout << (isBST(nums)?1:0) << endl;
    }
    return 0;
}