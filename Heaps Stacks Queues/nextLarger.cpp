// https://app.codesignal.com/interview-practice/task/MdHZFgZFERPPagfdD

std::vector<int> nextLarger(std::vector<int> a) {
    stack <int> s;
    vector <int> ret;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (s.empty()) {
            ret.push_back(-1);
        } else if (s.top() > a[i]) {
            ret.push_back(s.top());
        } else {
            while (!s.empty() && s.top() < a[i]) s.pop();
            ret.push_back(s.empty() ? -1 : s.top());
        }
        s.push(a[i]);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
