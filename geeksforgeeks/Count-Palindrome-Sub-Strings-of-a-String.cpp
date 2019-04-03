#include <iostream>
#include <string>
using namespace std;


int countPalindromeSubstr(const string &s){
    int n=s.size();
    bool dp[n];
    int ans=0;
    for(int i=0;i<n;++i)dp[i]=false;
    for(int i=n-1;i>=0;--i){
        dp[i]=true;
        for(int j=n-1;j>i+1;--j){
            dp[j] = s[i]==s[j] && dp[j-1];
            ans += dp[j];
        }
        if(i+1<n){
            dp[i+1]=s[i]==s[i+1];
            ans += dp[i+1];
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;string s;
        cin>>n>>s;
        cout << countPalindromeSubstr(s) << endl;
    }
    return 0;
}