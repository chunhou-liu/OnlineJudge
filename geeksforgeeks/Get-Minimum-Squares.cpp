#include <iostream>
#include <vector>
using namespace std;


int minimumSquare(int n){
    int dp[n+1];
    dp[0]=0;dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;++i){
        dp[i]=i;
        for(int j=1;j*j<=i;++j)dp[i]=min(dp[i], dp[i-j*j]+1);
    }
    return dp[n];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << minimumSquare(n) << endl;
    }
    return 0;
}