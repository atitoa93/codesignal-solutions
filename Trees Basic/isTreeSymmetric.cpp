// https://app.codesignal.com/interview-practice/task/tXN6wQsTknDT6bNrf

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool solve(Tree<int> *a, Tree<int> *b) {
    if (!a || !b) return !a && !b;
    return a->value == b->value && solve(a->left, b->right) && solve(a->right, b->left);
}

bool isTreeSymmetric(Tree<int> * t) {
    if (!t) return true;
    return solve(t->left, t->right);
}
