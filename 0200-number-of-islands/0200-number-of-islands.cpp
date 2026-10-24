class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<char>>& grid) {
                int m = grid.size();
                int n = grid[0].size();
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (i > 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
                visited[i - 1][j] = 1;
                q.push({i - 1, j});
            }
            if (j > 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                visited[i][j - 1] = 1;
                q.push({i, j - 1});
            }
            if (j + 1 < n && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                visited[i][j + 1] = 1;
                q.push({i, j + 1});
            }
            if (i + 1 < m && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                visited[i + 1][j] = 1;
                q.push({i + 1, j});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (!visited[i][j]) {
                        ans++;
                        bfs(i, j, visited, grid);
                    }
                }
            }
        }
        return ans;
    }
};





/*class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};*/






