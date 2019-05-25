// https://app.codesignal.com/interview-practice/task/5A8jwLGcEpTPyyjTB

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int n = a.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
            int t1 = a[i][j];
            int t2 = a[j][n - 1 - i];
            int t3 = a[n - 1 - i][n - 1 - j];
            int t4 = a[n - 1 - j][i];
            a[i][j] = t4;
            a[j][n - 1 - i] = t1;
            a[n - 1 - i][n - 1 - j] = t2;
            a[n - 1 - j][i] = t3;
        }
    }
    
    return a;
}
