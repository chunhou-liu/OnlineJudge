#include <climits>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum_ends_with(A), sum_starts_with(A);
        for(int i=1;i<A.size();++i)sum_ends_with[i]+=sum_ends_with[i-1];
        for(int i=A.size()-2;i>=0;--i)sum_starts_with[i]+=sum_starts_with[i+1];
        int case1 = helper(A, sum_ends_with, sum_starts_with, L, M);
        int case2 = helper(A, sum_ends_with, sum_starts_with, M, L);
        return max(case1, case2);
    }
    int helper(vector<int> &A, vector<int> &sum_ends_with, vector<int> &sum_starts_with, int L, int M){
        int ans = INT_MIN;
        for(int i=L-1; i<A.size()-M; ++i){
            int prev_sum = i==L-1?sum_ends_with[i]: sum_ends_with[i]-sum_ends_with[i-L];
            for(int j=i+1; j<=A.size()-M; ++j){
                int post_sum = j==A.size()-M?sum_starts_with[j]:sum_starts_with[j]-sum_starts_with[j+M];
                ans = max(ans, prev_sum+post_sum);
            }
        }
        return ans;
    }
};