#include <iostream>
#include <vector>
using namespace std;


int minimumOperations(int n){
    vector<int> dp(n+1, 0);
    dp[1]=1;
    for(int i=2;i<=n;++i)
        if(i%2==1)dp[i]=dp[i-1]+1;
        else dp[i]=1+dp[i/2];
    return dp[n];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << minimumOperations(n) << endl;
    }
    return 0;
}