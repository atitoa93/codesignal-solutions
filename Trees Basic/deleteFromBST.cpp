// https://app.codesignal.com/interview-practice/task/oZXs4td52fsdWC9kR

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };


Tree<int>* remove(Tree <int> *cur, Tree <int> *parent, int val) {
    if (!cur) return nullptr;
    if (cur->value == val)  {
        if (!cur->left && !cur->right) {
            if (!parent) {
                
            } else if (parent->left == cur) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete cur;
            return nullptr;
        }
        if (!cur->left || !cur->left) {
            Tree <int> *tmp = cur;
            cur = cur->left ? cur->left : cur->right;
            if (!parent) {
                
            } else if (parent->left == tmp) {
                parent->left = cur;
            } else {
                parent->right = cur;
            }
            delete tmp;
            return cur;
        }
        Tree <int> *leftRightMost = cur->left;
        Tree <int> *parentLeftRightMost = nullptr;
        while (leftRightMost->right) {
            parentLeftRightMost = leftRightMost;
            leftRightMost = leftRightMost->right;
        }
        if (leftRightMost->left) {
            if (parentLeftRightMost) parentLeftRightMost->right = leftRightMost->left;
            else cur->left = leftRightMost->left;
        } else {
            if (parentLeftRightMost) parentLeftRightMost->right = nullptr;
            else cur->left = nullptr;
        }        
        
        cur->value = leftRightMost->value;
        delete leftRightMost;
        return cur;
    }
    else if (cur->value > val) return remove(cur->left, cur, val);
    else return remove(cur->right, cur, val);
}

Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
    for (int q : queries) {
        bool isRoot = t ? t->value == q : false;
        Tree <int> *node = remove(t, nullptr, q);
        if (isRoot) t = node;
    }
    return t;
}
