class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int num: nums) {
            if(m[num]++ != 0) {
                return true;
            }
        }
        return false;
    }
};