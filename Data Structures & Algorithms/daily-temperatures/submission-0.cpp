class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        stack<int> s;
        s.push(0);

        for(int i = 1; i < n; ++i) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            
            s.push(i);
        }
        return result;
    }
};
