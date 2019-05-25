// https://app.codesignal.com/interview-practice/task/RvDFbsNC3Xn7pnQfH

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    vector <int> A, B;
    while (a) {
        A.push_back(a->value);
        a = a->next;
    }
    reverse(A.begin(), A.end());
    while (b) {
        B.push_back(b->value);
        b = b->next;
    }
    reverse(B.begin(), B.end());
    
    if (A.size() > B.size()) swap(A, B);
    
    vector <int> res;
    int carry = 0;
    for (int i = 0; i < A.size(); ++i) {
        int t = A[i] + B[i] + carry;
        carry = t / 10000;
        t %= 10000;
        res.push_back(t);
    }
    for (int i = A.size(); i < B.size(); ++i) {
        int t = B[i] + carry;
        carry = t / 10000;
        t %= 10000;
        res.push_back(t);
    }
    if (carry) res.push_back(1);
    reverse(res.begin(), res.end());
    
    ListNode<int> *ret = nullptr, *cur, *tmp;
    for (int i = 0; i < res.size(); ++i) {
        tmp = new ListNode<int> (res[i]);
        if (!ret) ret = cur = tmp;
        else cur->next = tmp, cur = cur->next;
    }
    return ret;
}
