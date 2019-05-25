// https://app.codesignal.com/interview-practice/task/njfXsvjRthFKmMwLC

bool containsCloseNums(std::vector<int> nums, int k) {
    unordered_map <int, vector <int>> m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]].push_back(i);
    }
    
    for (auto v : m) {
        for (int i = 0; i < v.second.size(); ++i) {
            if (!i) continue;
            if (v.second[i] - v.second[i - 1] <= k) {
                return true;
            }
        }
    }
    
    return false;
}
