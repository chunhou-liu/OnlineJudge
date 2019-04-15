#include <string>
#include <iostream>
using namespace std;


int maxPalindrome(const string &s){
    int n = s.size();
    int dp[n][n];
    for(int i=0;i<n;++i)dp[i][i]=1;
    for(int i=0;i<n-1;++i)dp[i][i+1]= s[i]==s[i+1]?2:1;
    for(int i=n-2;i>=0;--i){
        for(int j=i+2;j<n;++j){
            if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


int main(){
    string s;
    while(cin>>s){
        cout << s.size() - maxPalindrome(s) << endl;
    }
    return 0;
}