// https://app.codesignal.com/interview-practice/task/BG94ZFECSNo6Kv7XW

int partition(vector <int> &a, int s, int e) {
    swap(a[s + rand() % (e - s + 1)], a[e]);
    int j = s;
    for (int i = s; i < e; ++i) {
        if (a[i] > a[e]) {
            swap(a[i], a[j]);
            ++j;
        }
    }
    swap (a[j], a[e]);
    return j;
}

int bt(vector <int> &a, int s, int e, int k) {
    int p = partition(a, s, e);
    return p == k ? a[p] : p > k ? bt(a, s, p - 1, k) : bt(a, p + 1, e, k);
}

int kthLargestElement(vector<int> nums, int k) {
    return bt(nums, 0, nums.size() - 1, k - 1);
}
