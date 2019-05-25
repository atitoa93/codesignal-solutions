// https://app.codesignal.com/interview-practice/task/HmNvEkfFShPhREMn4

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode <int> *f;
bool isListPalindrome(ListNode<int> * l) {
    // static ListNode <int> *f;
    if (!f) f = l;
    if (!l) return true;
    bool ret = true;
    ret &= isListPalindrome(l->next);
    if (l->value != f->value) return false;
    f = f->next;
    return ret;
}
