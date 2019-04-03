#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &nums){
    int n=nums.size();
    // reverse each row
    for(int i=0;i<n;++i){
        for(int j=0, k=n-1;j<k;++j,--k)swap(nums[i][j], nums[i][k]);
    }
    // reverse by the diagonal line
    for(int i=0;i<n;++i){
        for(int j=n-i;j<n;++j){
            swap(nums[i][j], nums[n-1-j][n-1-i]);
        }
    }
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<vector<int>> nums(n, vector<int>(n));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)cin>>nums[i][j];
        rotate(nums);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}