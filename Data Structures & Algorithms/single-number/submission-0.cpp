class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;

        for(int num: nums) {
            if (m[num]) {
                m.erase(num);
            }
            else {
                m[num]++;
            }
        }
        return (*m.begin()).first;
    }
};
