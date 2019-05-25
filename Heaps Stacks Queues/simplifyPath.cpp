// https://app.codesignal.com/interview-practice/task/aRwxhGcmvhf6vKPCp

std::string simplifyPath(std::string path) {
    string t;
    stack <string> s;
    stringstream ss(path);
    while (getline(ss, t, '/')) {
        if (t == "" || t == "." || (t == ".." && s.empty())) continue;
        if (t == "..") s.pop();
        else s.push(t);
    }
    vector <string> v;
    while (!s.empty()) v.push_back(s.top()), s.pop();
    reverse(v.begin(), v.end());
    string ret = v.empty() ? "/" : "";
    for (string t : v) ret += "/" + t;
    return ret;
}
