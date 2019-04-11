#include <iostream>
#include <vector>
using namespace std;


int maxBitonicSubseq(vector<int> &A){
    int n=A.size();
    vector<int> incr_dp(A), decr_dp(A);
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(A[j]<A[i])incr_dp[i]=max(incr_dp[i], A[i]+incr_dp[j]);
        }
    }
    for(int i=n-2;i>=0;--i){
        for(int j=i+1;j<n;++j){
            if(A[j]<A[i])decr_dp[i]=max(decr_dp[i], A[i]+decr_dp[j]);
        }
    }
    int ans=incr_dp[0]+decr_dp[0]-A[0];
    for(int i=1;i<n;++i)
        ans=max(ans, incr_dp[i]+decr_dp[i]-A[i]);
    return ans;
}

int main(){
    int T;cin>>T;
    while(T-->0){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;++i)cin>>A[i];
        cout << maxBitonicSubseq(A) << endl;
    }
    return 0;
}