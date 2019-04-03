bool compare(struct val &obj1, struct val &obj2){
    return obj1.first < obj2.first;
}

int maxChainLen(struct val p[],int n){
    sort(p, p+n, compare);
    int dp[n], ans=1;
    dp[0]=1;
    for(int end=1;end<n;++end){
        dp[end]=1;
        for(int start=0;start<end;++start){
            if(p[start].second < p[end].first)dp[end]=max(dp[end], dp[start]+1);
        }
        ans=max(ans, dp[end]);
    }
    return ans;
}