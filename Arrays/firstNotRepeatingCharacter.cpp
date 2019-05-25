// https://app.codesignal.com/interview-practice/task/uX5iLwhc6L5ckSyNC

char firstNotRepeatingCharacter(std::string s) {
    vector <pair <int, int>> freq(26);
    
    for (int i = s.size() - 1; i >= 0; --i) {
        freq[s[i] - 'a'].first++;
        freq[s[i] - 'a'].second = i;
    }
    
    char ret = '_';
    int minIdx = s.size();
    for (int i = 0; i < 26; ++i) {
        if (freq[i].first == 1 && freq[i].second < minIdx) {
            minIdx = freq[i].second;
            ret = 'a' + i;
        } 
    }
    
    return ret;
}
