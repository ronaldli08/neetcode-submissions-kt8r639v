class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int n = heights.size();
        int p2 = n - 1;

        int mA = 0;

        while(p1 < p2) {
            mA = max(mA, min(heights[p1], heights[p2]) * (p2-p1));
            if(heights[p1] < heights[p2])
                ++p1;
            else
                --p2;
        }
        return mA;
    }
};
