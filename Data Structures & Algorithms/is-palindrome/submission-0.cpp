class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size() - 1;
        while(p1 < p2) {
            if(!isalnum(s[p1])) {
                ++p1;
                continue;
            }
            if(!isalnum(s[p2])) {
                --p2;
                continue;
            }
            if(tolower(s[p1]) != tolower(s[p2])) return false;
            ++p1;
            --p2;
        }
        return true;
    }
};
