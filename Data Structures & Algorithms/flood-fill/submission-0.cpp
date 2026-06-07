class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int og = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        while(!q.empty()) {
            pair<int,int> front = q.front();
            q.pop();
            image[front.first][front.second] = color;
            if(front.first > 0 && image[front.first - 1][front.second] == og && !visited[front.first - 1][front.second] ) {
                q.push({front.first - 1, front.second});
                visited[front.first - 1][front.second] = true;
            }
            if(front.first < m - 1 && image[front.first + 1][front.second] == og && !visited[front.first + 1][front.second] ) {
                q.push({front.first + 1, front.second});
                visited[front.first + 1][front.second] = true;
            }
            if(front.second > 0 && image[front.first][front.second - 1] == og && !visited[front.first][front.second-1] ) {
                q.push({front.first, front.second - 1});
                visited[front.first][front.second - 1] = true;
            }
            if(front.second < n - 1 && image[front.first][front.second + 1] == og && !visited[front.first][front.second+1] ) {
                q.push({front.first, front.second + 1});
                visited[front.first][front.second + 1] = true;
            }
        }
        return image;
    }
};