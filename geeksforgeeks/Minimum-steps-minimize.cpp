#include <iostream>
using namespace std;

int minimumSteps(int N){
    int dp[N+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=N;++i){
        dp[i] = dp[i-1]+1;
        if(i%2==0)dp[i]=min(dp[i], dp[i/2]+1);
        if(i%3==0)dp[i]=min(dp[i], dp[i/3]+1);
    }
    return dp[N];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int N;cin>>N;
        cout << minimumSteps(N) << endl;
    }
    return 0;
}