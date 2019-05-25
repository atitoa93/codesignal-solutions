// https://app.codesignal.com/interview-practice/task/rMe9ypPJkXgk3MHhZ

void bt(vector <int> &c, vector <int> &q, unordered_set <int> &sums, int idx, int sum) {
    if (idx == c.size()) {
        if (sum) sums.insert(sum);
        return;
    }
    
    for (int i = 0; i <= q[idx]; ++i) {
        bt(c, q, sums, idx + 1, sum + c[idx] * i);
    }
}

int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
    unordered_set <int> sums;
    bt(coins, quantity, sums, 0, 0);
    return sums.size();
}
