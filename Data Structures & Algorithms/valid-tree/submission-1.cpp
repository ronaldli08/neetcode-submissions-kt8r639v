class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        bool val = dfs(0, adj, -1, visited);
        for(auto b:visited) {
            if (!b) {
                return false;
            }
        }
        return val;
    }

    bool dfs(int node, vector<vector<int>>& edges, int parent, vector<bool>& visited) {
        for (int edge:edges[node]) {
            if (visited[edge] && edge != parent) {
                return false;
            }
            else if (edge != parent){
                visited[edge] = true;
                if(!dfs(edge, edges, node, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
 };
