#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int res=0, neg_count=0, min_abs_val = INT_MAX;
        for(int i=0;i<A.size();++i){
            neg_count += A[i]<0?1:0;
            min_abs_val = min(min_abs_val, abs(A[i]));
        }
        sort(A.begin(), A.end());
        if(K<=neg_count){
            for(int i=0; i<K;++i)res+=-A[i];
            for(int i=K;i<A.size();++i)res+=A[i];
        }else{
            for(int i=0;i<A.size();++i)res+=abs(A[i]);
            if((K-neg_count)%2==1)res-=2*min_abs_val;
        }
        return res;
    }
};