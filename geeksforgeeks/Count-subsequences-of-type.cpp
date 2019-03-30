#include <iostream>
#include <string>
#include <vector>
using namespace std;


int counting(const string &s){
    int ans=0;
    int n=s.size();
    vector<int> dp(n, 0);
    for(int i=n-1;i>=0;--i){
        dp[i]= s[i]=='c'?1:0;
        for(int j=i+1;j<n;++j){
            if(s[j]==s[i] || s[j]==s[i]+1)dp[i]+=dp[j];
        }
        if(s[i]=='a')ans+=dp[i];
    }
    return ans;
}


int main(){
    int T;cin>>T;
    for(int i=0;i<T;++i){
        string s;cin>>s;
        cout << counting(s) << endl;
    }
    return 0;
}