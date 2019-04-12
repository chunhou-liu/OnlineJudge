#include <iostream>
#include <vector>
using namespace std;


int rodCut(int n, vector<int> &price){
    vector<int> dp(n, 0);
    dp[0]=price[0];
    for(int i=1;i<n;++i){
        dp[i]=price[i];
        for(int j=0;j<i;++j)dp[i]=max(dp[i], price[i-j-1]+dp[j]);
    }
    return dp[n-1];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int N;cin>>N;
        vector<int> price(N);
        for(int i=0;i<N;++i)cin>>price[i];
        cout << rodCut(N, price) << endl;
    }
    return 0;
}