class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num:nums) {
            if(m[num]) {
                return num;
            }
            else{
                m[num]++;
            }
        }
        return 0;
    }
};
