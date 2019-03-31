#include <iostream>
using namespace std;


int uniqueBST(int low, int high){
    if(low>=high)return 1;
    int ans=0;
    for(int t=low;t<=high;++t){
        ans += uniqueBST(low, t-1)*uniqueBST(t+1, high);
    }
    return ans;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << uniqueBST(1, n) << endl;
    }
    return 0;
}