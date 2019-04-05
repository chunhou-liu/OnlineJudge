#include <iostream>
using namespace std;


int modularExponentiation(int A, int B, int C){
    int ans = 1, mod=A%C;
    for(int i=0;i<B;++i){
        ans = (ans%C*mod)%C;
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-- > 0){
        int A,B,C;
        cin>>A>>B>>C;
        cout << modularExponentiation(A,B,C) << endl;
    }
    return 0;
}