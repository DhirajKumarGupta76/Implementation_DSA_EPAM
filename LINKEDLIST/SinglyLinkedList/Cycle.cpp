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

    vector<ListNode*> nodes;
    nodes.push_back(head);

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
        nodes.push_back(tail);
    }

    // Manually create a cycle
    // Last node points to node at index 1 (2nd node)
    if (n > 1)
        tail->next = nodes[1];

    return head;
}

class Solution {
public:
    bool solve(ListNode* head) {

        // Write Floyd Cycle Detection Logic Here

    }
};

int main() {

    int n;
    cin >> n;

    ListNode* head = buildList(n);

    Solution obj;

    if (obj.solve(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}