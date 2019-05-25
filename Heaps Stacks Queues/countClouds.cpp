// https://app.codesignal.com/interview-practice/task/HdgqPhHqs3NciAHqH

void bt(vector <vector <char>> &g, int n, int m, int x, int y, int dx[], int dy[]) {
    g[x][y] = '0';
    for (int d = 0; d < 4; ++d) {
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '1') {
            bt(g, n, m, nx, ny, dx, dy);
        }
    }
}

int countClouds(std::vector<std::vector<char>> skyMap) {
    int n = skyMap.size();
    int m = n ? skyMap[0].size() : 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (skyMap[i][j] == '1') {
               ++ret;
                bt(skyMap, n, m, i, j, dx, dy);
            }
        }
    }
    return ret;
}
