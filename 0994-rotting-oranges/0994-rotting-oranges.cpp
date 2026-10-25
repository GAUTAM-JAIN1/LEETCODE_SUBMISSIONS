
class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited,
            queue<pair<int, pair<int, int>>>& q) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        while (!q.empty()) {
            int t = q.front().first;
            int a = q.front().second.first;
            int b = q.front().second.second;
            q.pop();

            ans = max(ans, t);

            if (a + 1 < m && grid[a + 1][b] == 1 && visited[a + 1][b] == 0) {
                q.push({t + 1, {a + 1, b}});
                visited[a + 1][b] = 1;
            }

            if (a - 1 >= 0 && grid[a - 1][b] == 1 && visited[a - 1][b] == 0) {
                q.push({t + 1, {a - 1, b}});
                visited[a - 1][b] = 1;
            }

            if (b + 1 < n && grid[a][b + 1] == 1 && visited[a][b + 1] == 0) {
                q.push({t + 1, {a, b + 1}});
                visited[a][b + 1] = 1;
            }

            if (b - 1 >= 0 && grid[a][b - 1] == 1 && visited[a][b - 1] == 0) {
                q.push({t + 1, {a, b - 1}});
                visited[a][b - 1] = 1;
            }
        }

        return ans;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    visited[i][j] = 1;
            }
        }

        int ans = bfs(grid, visited, q);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    return -1;
            }
        }

        return ans;
    }
};
