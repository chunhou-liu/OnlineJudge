#include <vector>
#include <iostream>
using namespace std;


int numberOfHops(int N){
    if(N<3)return N;
    if(N==3)return 4;
    vector<int> dp(N);
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    for(int i=3;i<N;++i)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    return dp[N-1];
}

int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << numberOfHops(n) << endl;
    }
    return 0;
}