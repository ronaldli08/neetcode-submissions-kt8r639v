class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, int> m;
        for(const int& num:nums) {
            ++m[num];
        }
        int prev = m.begin()->first;
        m.erase(m.begin());
        int maxL = 1;
        int len = 1;
        for(const auto& p:m) {
            if(prev + 1 != p.first) {
                maxL = max(maxL, len);
                len = 0;
            }
            ++len;
            prev = p.first;
        }
        return max(len,maxL);
    }
};
