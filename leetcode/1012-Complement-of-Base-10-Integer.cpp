class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        int ans;
        for(int i=0;i<32;++i){
        	ans = 0x1 << i;
        	if(ans>N)break;
        }
        return int(ans-1-N);
    }
};