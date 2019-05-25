// https://app.codesignal.com/interview-practice/task/dYCH8sdnxGf5aGkez

int findMatchedBracket(string &s, int l) {
    int ret = l + 1, oddEven = 0;
    while (ret < s.size()) {
        if (s[ret] == ']' && !oddEven) break;
        
        if (s[ret] == '[') ++oddEven;
        if (s[ret] == ']') --oddEven;
        
        ++ret;
    }
    return ret;
}

string bt(string s) {
    int l = s.find_first_of('[');
    if (l == -1) return s;
    int r = findMatchedBracket(s, l);
    int k = 0, ll = l - 1;
    while (ll >= 0 && s[ll] >= '0' && s[ll] <= '9') --ll;
    ++ll;
    string f = s.substr(0, ll);
    while (ll < l) k = k * 10 + s[ll] - '0', ++ll;
    string t = bt(s.substr(l + 1, r - l - 1));
    string tt = "";
    while (k) tt += t, --k;
    return bt(f + tt + s.substr(r + 1));
}

std::string decodeString(std::string s) {
    return bt(s);
}
