class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n - 1];

        int p1 = 1;
        int p2 = n - 2;

        int total = 0;

        while(p1 <= p2) {
            if(lmax < rmax) {
                total += max(0, lmax - height[p1]);
                lmax = max(lmax, height[p1]);
                ++p1;
            }
            else {
                total += max(0, rmax - height[p2]);
                rmax = max(rmax, height[p2]);
                --p2;
            }
        }
        
        return total;
    }
};
