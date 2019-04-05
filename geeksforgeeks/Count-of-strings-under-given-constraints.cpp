#include <iostream>
#include <algorithm>
using namespace std;

int countOfStrings(int n){
    int ans = 0;
    // without b
        // without c
    ans += 1;
        // with one c
    ans += max(0, n);
        // with two c
    ans += max(0, n*(n-1)/2);
    // with one b
        // without c
    ans += max(0, n);
        // with one c
    ans += max(n*(n-1), 0);
        // with two c
    ans += max(0, n*(n-1)*(n-2)/2);
    return ans;
}

int main(){
    int T;cin>>T;
    while(T-- > 0){
        int n;cin>>n;
        cout << countOfStrings(n) << endl;
    }
    return 0;
}