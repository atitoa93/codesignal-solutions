// https://app.codesignal.com/interview-practice/task/jAKLMWLu8ynBhYsv6

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
// 

void solve(Tree <int> *t, int &k, int &ret) {
    if (!t || !k) return;
    solve(t->left, k, ret);
    --k;
    if (!k) ret = t->value;
    solve(t->right, k, ret);
}

int kthSmallestInBST(Tree<int> * t, int k) {
    int ret = 0;
    solve(t, k, ret);
    return ret;
}
