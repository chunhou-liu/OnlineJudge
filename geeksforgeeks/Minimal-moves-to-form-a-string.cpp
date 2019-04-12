#include <string>
#include <iostream>
using namespace std;


int minimumMoves(const string &s){
    int n = s.size();
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+1;
        if(i%2==0){
            if(s.substr(0, i/2)==s.substr(i/2, i/2))dp[i]=min(dp[i], dp[i/2]+1);
        }
    }
    return dp[n];
}


int main(){
    int T;cin>>T;
    while(T-->0){
        string s;cin>>s;
        cout << minimumMoves(s) << endl;
    }
    return 0;
}