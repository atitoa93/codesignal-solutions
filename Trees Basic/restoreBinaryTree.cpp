// https://app.codesignal.com/interview-practice/task/AaWaYxi8gjtbqgp2M

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
Tree<int> * restoreBinaryTree(std::vector<int> in, std::vector<int> &pre) {
    if (in.empty()) return nullptr;
    
    Tree<int> *ret = new Tree<int> (pre[0]);
    
    int idx = 0;
    while (in[idx] != pre[0]) ++idx;
    
    pre.erase(pre.begin());
    ret->left = restoreBinaryTree(vector <int>(in.begin(), in.begin() + idx), pre);
    ret->right = restoreBinaryTree(vector <int>(in.begin() + idx + 1, in.end()), pre);
    
    return ret;
}
