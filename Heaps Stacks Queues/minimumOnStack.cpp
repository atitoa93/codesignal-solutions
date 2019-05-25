// https://app.codesignal.com/interview-practice/task/gnZYGn367s4yaHvRr

std::vector<int> minimumOnStack(std::vector<std::string> operations) {
    vector <int> ret;
    stack <int> s;
    for (int i = 0; i < operations.size(); ++i) {
        stringstream ss(operations[i]);
        string op; ss >> op;
        if (op == "min") {
            ret.push_back(s.top());
        } else if (op == "push") {
            int val; ss >> val;
            if (s.empty()) s.push(val);
            else s.push(min(val, s.top()));
        } else {
            s.pop();
        }
    }
    return ret;
}
