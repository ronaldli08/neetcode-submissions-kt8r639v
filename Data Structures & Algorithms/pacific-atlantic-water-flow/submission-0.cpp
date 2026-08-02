class Solution {
public:
        vector<vector<bool>> pac;
        vector<vector<bool>> atl;
        vector<vector<bool>> visited;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        pac = vector<vector<bool>>(n, vector<bool>(m, false));
        atl = vector<vector<bool>>(n, vector<bool>(m, false));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        vector<vector<int>> output;

        for(int i = 0; i < n; i++) {
            dfs(i, 0, n, m, true, heights);
            dfs(i, m-1, n,m,false,heights);
        }
        for(int j = 0; j < m; j++) {
            dfs(0, j, n, m, true,heights);
            dfs(n-1, j, n,m,false,heights);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pac[i][j] && atl[i][j]) {
                    output.push_back({i,j});
                }
            }
        }
        return output;
    }
    void dfs(int i, int j, int n, int m, bool ocean, vector<vector<int>>& heights) {
        if(ocean) pac[i][j] = true;
        else atl[i][j] = true;
        if(i > 0 && heights[i-1][j] >= heights[i][j] && !visited[i-1][j]) {
            visited[i-1][j] = true;
            dfs(i-1,j,n,m, ocean, heights);
            visited[i-1][j] = false;
        }
        if(j > 0 && heights[i][j-1] >= heights[i][j] && !visited[i][j-1]) {
            visited[i][j-1] = true;
            dfs(i,j-1, n,m,ocean, heights);
            visited[i][j-1] = false;
        }
        if(i < n - 1 && heights[i+1][j] >= heights[i][j] && !visited[i+1][j]) {
            visited[i+1][j] = true;
            dfs(i+1,j, n, m,ocean,heights);
            visited[i+1][j] = false;
        }
        if(j < m - 1 && heights[i][j+1] >= heights[i][j] && !visited[i][j+1]) {
            visited[i][j+1] = true;
            dfs(i,j+1,n, m,ocean,heights);
            visited[i][j+1] = false;
        }
    }
};
