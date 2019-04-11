#include <vector>
#include <iostream>
using namespace std;


int minimumTime(vector<int> &A){
    int n=A.size();
    vector<int> dp(A.size(), 0);
    dp[0]=A[0];
    dp[1]=A[1];
    for(int i=2;i<A.size();++i){
        dp[i] = A[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        cout << minimumTime(A) << endl;
    }
    return 0;
}