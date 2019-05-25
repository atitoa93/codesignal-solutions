// https://app.codesignal.com/interview-practice/task/3PcnSKuRkqzp8F6BN

bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
    unordered_map <string, vector <int>> m1;
    for (int i = 0; i < strings.size(); ++i) {
        m1[strings[i]].push_back(i);
    }
    
    unordered_map <string, vector <int>> m2;
    for (int i = 0; i < patterns.size(); ++i) {
        m2[patterns[i]].push_back(i);
    }
    
    for (int i = 0; i < strings.size(); ++i) {
        if (m1[strings[i]] != m2[patterns[i]]) {
            return false;
        }
    }
    
    return true;
}
