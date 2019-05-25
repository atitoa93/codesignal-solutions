// https://app.codesignal.com/interview-practice/task/gX7NXPBrYThXZuanm

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    ListNode <int> *prev = 0, *ret = l;
    while (l) {
        if (l->value == k) {
            ListNode <int> *tmp = l;
            l = l->next;
            if (prev) prev->next = l;
            else ret = l;
            delete tmp;
        } else {
            prev = l;
            l = l->next;
        }
    }
    return ret;
}
