#include <iostream>
#include <vector>
#include <string>
using namespace std;


int increaseSubSequence(const string &s){
    int n=s.size(), ans=1;
    vector<int> dp(n, 1);
    for(int i=2;i<n;++i){
        for(int j=0;j<i;++j)
            if(s[j]<s[i])dp[i]=max(dp[i], dp[j]+1);
        ans=max(ans, dp[i]);
    }
    return ans;
}


int main(){
    int T;cin>>T;
    for(int i=0;i<T;++i){
        string s;
        cin>>s;
        cout << increaseSubSequence(s) << endl;
    }
    return 0;
}