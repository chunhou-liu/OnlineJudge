#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<2)return true;
        for(int left=0, right=s.size()-1;left<right;++left, --right){
            while(left<right && !isalnum(s[left]))++left;
            while(left<right && !isalnum(s[right]))--right;
            if(left<right && tolower(s[left])!=tolower(s[right]))return false;
        }
        return true;
    }
};