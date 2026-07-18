class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> possible(n, false);
        possible[n-1] = true;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j <= i + nums[i] && j < n; j++) {
                if(possible[j]) possible[i] = true;
            }
        }
        return possible[0];
    }
};
