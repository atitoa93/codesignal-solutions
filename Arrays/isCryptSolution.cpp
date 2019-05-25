// https://app.codesignal.com/interview-practice/task/yM4uWYeQTHzYewW9H

int solValue(vector <vector <char>> s, char ch) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i][0] == ch) return s[i][1] - '0';
    }
    return 0;
}

long long calc(string s, vector <vector <char>> sol) {
    long long ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret = ret * 10 + solValue(sol, s[i]);
    }
    return ret;
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    if (!solValue(solution, crypt[0][0]) && crypt[0].size() > 1) return false;
    if (!solValue(solution, crypt[1][0]) && crypt[1].size() > 1) return false;
    if (!solValue(solution, crypt[2][0]) && crypt[2].size() > 1) return false;
    
    long long v1 = calc(crypt[0], solution);
    long long v2 = calc(crypt[1], solution);
    long long v3 = calc(crypt[2], solution);
    
    return v1 + v2 == v3;
}
