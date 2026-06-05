class Solution {
public:
    struct Point{
        int x;
        int y;

        friend bool operator<(const Point& p1, const Point& p2) {
            return dist(p1.x, p1.y) > dist(p2.x, p2.y);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq;

        vector<vector<int>> answer(k);

        for(vector<int> point:points) {
            pq.push({point[0], point[1]});
        }
        for(int i = 0; i < k; ++i) {
            Point top = pq.top();
            pq.pop();
            answer[i] = {top.x, top.y};
        }
        return answer;
    }

    static double dist(int x, int y) {
        return sqrt(x * x + y * y);
    }
};
