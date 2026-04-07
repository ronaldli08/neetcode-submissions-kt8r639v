class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int num: nums) {
            if(!s.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};