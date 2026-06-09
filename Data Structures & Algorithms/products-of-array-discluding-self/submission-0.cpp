class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long geoSum = 1;
        long long exSum = 1;
        int numZeros = 0;
        for(const int& num:nums) {
            if(num != 0) geoSum *= num;
            else ++numZeros;}
        vector<int> output(nums.size(), 0);
        if(numZeros > 1) return output;
        else if(numZeros == 1) {
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] == 0) {
                    output[i] = geoSum;
                    return output;
                }
            }
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            output[i] = geoSum / nums[i];
        }
        return output;
    }
};
