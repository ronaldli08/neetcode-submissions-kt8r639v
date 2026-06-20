class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // need a left min and right boundary array
        
        int n = heights.size();
        stack<int> nearest;
        vector<int> left(n, -1);
        vector<int> right(n, n);

        for(int i = 0; i < n; ++i) {
            while(!nearest.empty() && heights[nearest.top()] >= heights[i]) {
                nearest.pop();
            }
            if(!nearest.empty()) left[i] = nearest.top();
            nearest.push(i);
        }
        while(!nearest.empty()) nearest.pop();
        for(int i = n - 1; i >= 0; --i) {
            while(!nearest.empty() && heights[nearest.top()] >= heights[i]) {
                nearest.pop();
            }
            if(!nearest.empty()) right[i] = nearest.top();
            nearest.push(i);
        }
        int maxA = 0;
        for(int i = 0; i < n; ++i) {
            int area = heights[i] * (right[i] - left[i] -2 + 1);
            maxA = max(maxA, area);
        }
        return maxA;
    }
};
