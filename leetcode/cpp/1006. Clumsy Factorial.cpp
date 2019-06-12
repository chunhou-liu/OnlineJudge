class Solution {
public:
    int clumsy(int N, int prev=1) {
        if(N<=2)return prev*N;
        if(N==3)return prev*6;
        if(N==4)return prev*6+1;
        return prev*N*(N-1)/(N-2)+N-3+clumsy(N-4, -1);
    }
};