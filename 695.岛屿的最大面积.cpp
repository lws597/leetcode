/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int area = 1;
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int _x = x + dir[k][0], _y = y + dir[k][1];
                            if ((_x >= 0 && _x < n && _y >= 0 && _y < m) && !visited[_x][_y] && grid[_x][_y] == 1) {
                                q.push({_x, _y});
                                visited[_x][_y] = true;
                                area++;
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

