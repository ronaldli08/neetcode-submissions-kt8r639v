class Solution {
public:
    int characterReplacement(string s, int k) {
        char cur = s[0];
        int n = s.size();
        if(n == 1) return 1;
        int left = 0;
        int right = 1;
        vector<int> alphabet(26, 0);
        alphabet[cur - 'A']++;
        int maxFreq = 1;
        int longest = 0;

        while(right < n) {
            alphabet[s[right] - 'A']++;
            maxFreq = max(maxFreq, alphabet[s[right]-'A']);
            while(right - left + 1 - maxFreq > k) {
                alphabet[s[left] - 'A']--;
                left++;
            }
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};
