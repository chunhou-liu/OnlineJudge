#include <iostream>
#include <vector>
using namespace std;


int uniquePaths(int m, int n){
    // dp[i][j]=dp[i-1][j]+dp[i][j-1];
    vector<int> dp(n, 1);
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j)dp[j]+=dp[j-1];
    }
    return dp[n-1];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int m, n;cin>>m>>n;
        cout << uniquePaths(m, n) << endl;
    }
    return 0;
}