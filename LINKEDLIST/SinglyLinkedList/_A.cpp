#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* buildList(int n) {
    if (n == 0) return NULL;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

class Solution {
public:
    ListNode* solve(ListNode* head) {
        return head;
    }
};

int main() {
    int n;
    cin >> n;

    ListNode* head = buildList(n);

    Solution obj;
    ListNode* ans = obj.solve(head);

    printList(ans);

    return 0;
}