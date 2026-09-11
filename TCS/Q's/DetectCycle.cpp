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

ListNode* buildCycleList(int n, int pos) {
    if (n == 0) return NULL;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;
    ListNode* cycleNode = (pos == 0) ? head : NULL;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;

        if (i == pos) {
            cycleNode = tail;
        }
    }

    if (pos != -1) {
        tail->next = cycleNode;
    }

    return head;
}

class Solution {
public:
    bool hasCycle(ListNode* head) {
          if(head==NULL || head->next==NULL) return false;
        ListNode * slow=head;
        ListNode *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
           
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;

        }
        return false;
    }
};

int main() {

     int pos;
     cout<<"Enter the Index Cycle Start ";
    cin >> pos;
   

    int n;
     cout<<"Enter the Size of linked list"<<endl;
    cin >> n;

   

    ListNode* head = buildCycleList(n, pos);

    Solution obj;
    bool ans = obj.hasCycle(head);

    cout << (ans ? "true" : "false");

    return 0;
}