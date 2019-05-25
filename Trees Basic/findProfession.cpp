// https://app.codesignal.com/interview-practice/task/FwAR7koSB3uYYsqDp

std::string findProfession(int level, int pos) {
    string ret = "Engineer";
    --level;
    while (level) {
        if (pos > (1 << (level - 1))) {
            pos -= (1 << (level - 1));
            ret = ret == "Engineer" ? "Doctor" : "Engineer";
        }
        --level;
    }
    return ret;
}
