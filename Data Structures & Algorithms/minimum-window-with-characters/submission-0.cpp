class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n2 >n1) return "";
        vector<int> a1(128, 0);
        vector<int> a2(128, 0);

        int minLen = INT_MAX;
        int start = -1;

        for(int i = 0; i < n2; i++) {
            a2[t[i]]++;
        }
        int left = 0;
        int right = 0;
        while(right < n1) {
            a1[s[right]]++;
            while(isPresent(a1, a2)) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                a1[s[left]]--;
                left++;
            }
            right++;
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
    bool isPresent(vector<int>& a1, vector<int>& a2) {
        for(int i = 0; i < 128; i++) {
            if(a1[i] < a2[i]) return false;
        }
        return true;
    }
};
