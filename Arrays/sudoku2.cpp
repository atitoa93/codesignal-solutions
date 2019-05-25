// https://app.codesignal.com/interview-practice/task/SKZ45AF99NpbnvgTn

bool sudoku2(std::vector<std::vector<char>> grid) {
    int r[9][9] = {};
    int c[9][9] = {};
    int s[9][9] = {};
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == '.') continue;
            int &t1 = r[i][grid[i][j] - '1'];
            int &t2 = c[j][grid[i][j] - '1'];
            int &t3 = s[i / 3 * 3 + j / 3][grid[i][j] - '1'];

            if (t1 || t2 || t3) {
                cout << i << " " << j << endl;
                return false;
            }
            t1 = t2 = t3 = 1;
        }
    }
    
    return true;
}
