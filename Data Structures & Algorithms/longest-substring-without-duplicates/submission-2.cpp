class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;

        if(n <= 1) return n;

        vector<int> alphabet(256, 0);

        int longest = 0;

        while(right < n) {
            while(alphabet[s[right]]) {
                alphabet[s[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
            alphabet[s[right]]++;
            right++;
        }
        return longest;
    }
};
