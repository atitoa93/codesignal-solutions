// https://app.codesignal.com/interview-practice/task/ndve2n4KH7dPBksLh

std::vector<int> nearestGreater(std::vector<int> a) {
    stack <pair <int, int>> s;
    vector <int> l, r;
    for (int i = 0; i < a.size(); ++i) {
        while (!s.empty() && s.top().first <= a[i]) s.pop();
        l.push_back(s.empty() ? -1 : s.top().second);
        s.push({ a[i], i });
    }
    while (!s.empty()) s.pop();
    for (int i = a.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top().first <= a[i]) s.pop();
        r.push_back(s.empty() ? -1 : s.top().second);
        s.push({ a[i], i });
    }
    reverse(r.begin(), r.end());
    vector <int> ret;
    for (int i = 0; i < a.size(); ++i) {
        if (l[i] == -1 && r[i] == -1) ret.push_back(-1);
        else if (l[i] == -1) ret.push_back(r[i]);
        else if (r[i] == -1) ret.push_back(l[i]);
        else if (i - l[i] <= r[i] - i) ret.push_back(l[i]);
        else ret.push_back(r[i]);
    }
    return ret;
}
