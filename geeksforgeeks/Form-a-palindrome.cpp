#include <string>
#include <iostream>
using namespace std;


int formAPalindrome(const string &s){
    int n=s.size();
    int dp[n][n];
    for(int i=0;i<n;++i)dp[i][i]=0;
    for(int i=0;i<n-1;++i)dp[i][i+1]= s[i]==s[i+1]?0:1;
    for(int i=n-1;i>=0;--i){
        for(int j=i+2;j<n;++j){
            if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=min(dp[i][j-1], dp[i+1][j])+1;
        }
    }
    return dp[0][n-1];
}


int main(){
    int T;cin>>T;
    string s;
    while(T-->0){
        cin>>s;
        cout << formAPalindrome(s) << endl;
    }
    return 0;
}