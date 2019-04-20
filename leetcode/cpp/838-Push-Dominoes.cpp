#include <string>
using namespace std;


class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int dp1[n], dp2[n];
        int r=-1, l=-1;
        for(int i=0;i<n;++i){
            if(dominoes[i]=='R'){
                dp1[i]=i;
                r=i;
                continue;
            }
            if(dominoes[i]=='L'){
                dp1[i]=-1;
                r=-1;
                continue;
            }
            dp1[i]=r;
        }
        for(int i=n-1;i>=0;--i){
            if(dominoes[i]=='L'){
                dp2[i]=i;
                l=i;
                continue;
            }
            if(dominoes[i]=='R'){
                dp2[i]=-1;
                l=-1;
                continue;
            }
            dp2[i]=l;
        }
        for(int i=0;i<dominoes.size();++i){
            if(dominoes[i]!='.')continue;
            if(dp1[i]==-1){
                if(dp2[i]==-1)continue;
                dominoes[i]='L';
            }else{
                if(dp2[i]==-1){dominoes[i]='R';continue;}
                if(i-dp1[i]<dp2[i]-i)dominoes[i]='R';
                else if(i-dp1[i]>dp2[i]-i)dominoes[i]='L';
            }
        }
        return dominoes;
    }
};