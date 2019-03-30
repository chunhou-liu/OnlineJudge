#include <iostream>
#include <vector>
using namespace std;


int maximumSum(int n){
    if(n<5)return n;
    vector<int> dp(n+1, 0);
    dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=3;dp[4]=4;
    for(int i=5;i<=n;++i)
        dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
    return dp[n];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << maximumSum(n) << endl;
    }
    return 0;
}