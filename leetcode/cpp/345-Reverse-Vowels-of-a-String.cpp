#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left=0, right=s.size()-1;
        auto isvowel = [](char c){return string("aeiouAEIOU").find(c)!=string::npos;};
        while(left<right){
            // first vowel
            while(left<right && !isvowel(s[left]))++left;
            while(left<right && !isvowel(s[right]))--right;
            if(left!=right){swap(s[left], s[right]);++left;--right;}
        }
        return s;
    }
};