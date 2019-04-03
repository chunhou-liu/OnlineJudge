#include <iostream>
#include <string>
using namespace std;


int LCS(const string &s, const string &t){
    int m=s.size(), n=t.size();
    int dp[m+1][n+1], ans=0;
    for(int i=0;i<=n;++i)dp[0][i]=0;
    for(int i=0;i<=m;++i)dp[i][0]=0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            ans=max(ans, dp[i][j]);
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int m, n;cin>>m>>n;
        string s, t; cin>>s>>t;
        cout << LCS(s, t) << endl;
    }
    return 0;
}