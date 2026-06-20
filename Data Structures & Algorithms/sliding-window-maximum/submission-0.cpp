class Solution {
public:
    struct Int{
        int num;

        friend bool operator<(const Int& i1, const Int& i2) {
            return i1.num > i2.num;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        if(k > n) {
            sort(nums.begin(), nums.end());
            return {*(nums.end()-1)};
        }
        
        map<Int, int> m;
        for(int i = 0;i < k; i++) {
            m[{nums[i]}]++;
        }
        ans.push_back(m.begin()->first.num);
        int p = k;
        while(p < n) {
            m[{nums[p]}]++;
            m[{nums[p - k]}]--;
            if(m[{nums[p - k]}] == 0) 
                m.erase(m.find({nums[p-k]}));
            ans.push_back(m.begin()->first.num);
            p++;
        }
        return ans;
    }
};
