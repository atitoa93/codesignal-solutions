// https://app.codesignal.com/interview-practice/task/xrFgR63cw7Nch4vXo

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
    map <string, set <string>> groups;
    for (int i = 0; i < dishes.size(); ++i) {
        for (int j = 1; j < dishes[i].size(); ++j) {
            groups[dishes[i][j]].insert(dishes[i][0]);
        }
    }
    
    vector <vector <string>> ret;
    for (auto mIt = groups.begin(); mIt != groups.end(); ++mIt) {
        if (mIt->second.size() <= 1) continue;
        ret.push_back(vector <string> (1, mIt->first));
        for (auto sIt = mIt->second.begin(); sIt != mIt->second.end(); ++sIt) {
            ret.back().push_back(*sIt);
        }
    }
    
    return ret;
}
