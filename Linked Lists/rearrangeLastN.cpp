// https://app.codesignal.com/interview-practice/task/5vcioHMkhGqkaQQYt

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

int length(ListNode <int> *cur) {
    return !cur ? 0 : length(cur->next) + 1;
}

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    ListNode <int> *start = l, *end = l, *newStart = l, *prev;
    
    int sz = length(l);
    
    if (!n || n == sz) return start;
    
    for (int i = 0; i < sz - n; ++i) {
        prev = newStart;
        newStart = newStart->next;
    }
    
    while (end->next) end = end->next;
    
    end->next = start;
    prev->next = nullptr;
    
    return newStart;
}
