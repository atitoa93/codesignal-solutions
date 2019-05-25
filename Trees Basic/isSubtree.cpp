// https://app.codesignal.com/interview-practice/task/mDpAJnDQkJqaYYsCg

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool isEqual(Tree <int> *t1, Tree <int> *t2) {
    if (!t1 || !t2) return !t1 && !t2;
    return t1->value == t2->value && isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
}

bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if (!t1) return !t2;
    return isEqual(t1, t2) || isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}
