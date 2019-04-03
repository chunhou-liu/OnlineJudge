#include <iostream>
using namespace std;


int contain4(int n){
    while(n!=0){
        if(n%10==4)return 1;
        n /= 10;
    }
    return 0;
}

int countNums(int n){
    int ans=0;
    for(int i=1;i<=n;++i)
        ans += contain4(i);
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << countNums(n) << endl;
    }
    return 0;
}