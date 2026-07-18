class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> jumps(n, INT_MAX - 1);

        jumps[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n && j <= i + nums[i]; j++) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
        return jumps[0];
    }
};
