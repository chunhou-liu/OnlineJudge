#include <string>
#include <iostream>
#include <vector>
using namespace std;


long long int sumOfSubstr(const string &s){
    long long int dp = 0;
    long long int ans=0;
    for(int i=0;i<s.size();++i){
        dp = dp*10 + (s[i]-'0')*(i+1);
        ans += dp;
    }
    return ans;
}


int main(){
    int T; cin>>T;
    while(T-->0){
        string s;cin>>s;
        cout << sumOfSubstr(s) << endl;
    }
    return 0;
}