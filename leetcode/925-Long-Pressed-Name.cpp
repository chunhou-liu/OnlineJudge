#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int left_index = 0, left_count = 0,
            right_index = 0, right_count = 0;
        while(left_index < name.size() && right_index < typed.size()){
            left_count = right_count = 0;
            char pivot = name[left_index];
            while(left_index < name.size() && name[left_index]==pivot){++left_index;++left_count;}
            while(right_index < typed.size() && typed[right_index]==pivot){++right_index;++right_count;}
            if(left_count>right_count)return false;
        }
        return left_index == name.size() && right_index == typed.size();
    }
};