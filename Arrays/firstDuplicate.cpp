// https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q

int firstDuplicate(std::vector<int> a) {
    vector <int> b(a.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        if (!b[a[i]]) b[a[i]] = 1;
        else return a[i];
    }
    return -1;
}
