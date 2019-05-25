// https://app.codesignal.com/interview-practice/task/6rE3maCQwrZS3Mm2H

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    ListNode <int> *ret = nullptr, *cur;
    while (l1 || l2) {
        if (l1 && l2) {
            if (l1->value < l2->value) {
                ListNode <int> *node = new ListNode(l1->value);
                if (!ret) ret = cur = node;
                else cur->next = node, cur = cur->next;
                l1 = l1->next;
            } else {
                ListNode <int> *node = new ListNode(l2->value);
                if (!ret) ret = cur = node;
                else cur->next = node, cur = cur->next;
                l2 = l2->next;
            }
        } else if (l1) {
            ListNode <int> *node = new ListNode(l1->value);
            if (!ret) ret = cur = node;
            else cur->next = node, cur = cur->next;
            l1 = l1->next;
        } else {
             ListNode <int> *node = new ListNode(l2->value);
            if (!ret) ret = cur = node;
            else cur->next = node, cur = cur->next;
            l2 = l2->next;
        }
    }
    return ret;
}
