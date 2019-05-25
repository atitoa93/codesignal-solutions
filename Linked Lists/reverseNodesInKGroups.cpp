// https://app.codesignal.com/interview-practice/task/XP2Wn9pwZW6hvqH67

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

ListNode <int> *next;

ListNode <int>* reverse(ListNode<int> *start, ListNode<int> *cur, int k, int i) {
    if (i == k) {
        next = cur;
        return start;
    }
    ListNode <int> *prev = reverse(start, cur->next, k, i + 1);
    prev->next = cur;
    return cur;
}

int length(ListNode <int> *cur) {
    if (!cur) return 0;
    return length(cur->next) + 1;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    int sz = length(l);
    ListNode <int> *start = new ListNode <int> (0), *root = start;
    start->next = l;
    next = l;
    for (int i = 0; i < sz / k; ++i) {
        start = reverse(start, next, k, 0);
    }
    if (sz % k != 0) start->next = next;
    else start->next = nullptr;
    return root->next;
}
