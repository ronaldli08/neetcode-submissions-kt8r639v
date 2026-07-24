class Solution {
public:

    vector<vector<string>> output;

    vector<vector<string>> partition(string s) {
        vector<string> cur;
        palin(0, 0, s, cur);
        return output;
    }

    void palin(int i, int j, const string& s, vector<string>& cur) {
        if(j == s.size()) {
            output.push_back(cur);
            return;
        }
        if(i == s.size()) {
            return;
        }
        string sub = s.substr(j, i - j + 1);
        if(isPalindrome(sub)) {
            cur.push_back(sub);
            palin(i + 1, i+ 1, s, cur);
            cur.pop_back();
        }
        palin(i+1, j, s, cur);
    }

    bool isPalindrome(const string &s) {
        int n = s.size();

        for(int i = 0; i < n / 2; ++i) {
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
};
