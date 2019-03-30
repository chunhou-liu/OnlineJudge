#include <iostream>
using namespace std;


int combinations(int target){
    int ans=0;
    for(int i=0;3*i<=target;++i){
        for(int j=0;3*i+5*j<=target;++j){
            if((target-3*i-5*j)%10==0)++ans;
        }
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << combinations(n) << endl;
    }
    return 0;
}