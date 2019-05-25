// https://app.codesignal.com/interview-practice/task/TG4tEMPnAc3PnzRCs

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool hasPathWithGivenSum(Tree<int> * t, int s) {
    if (!t) return false;
    if (!t->left && !t->right) return s == t->value;
    return hasPathWithGivenSum(t->left, s - t->value) || hasPathWithGivenSum(t->right, s - t->value);
}
