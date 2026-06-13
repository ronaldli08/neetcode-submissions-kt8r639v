class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for(int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<>());

        stack<double> time;
        for(int i = 0; i < n; ++i) {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if(!time.empty() && time.top() < t || time.empty()) {
                time.push(t);
            }
        }
        return time.size();
    }
};
