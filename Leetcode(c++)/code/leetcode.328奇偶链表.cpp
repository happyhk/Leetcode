/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *t = q;
        while(true) {
          if(q == nullptr || q->next == nullptr) break;
          p->next = q->next;
          p = p->next;
          q->next = p->next;
          q = q->next;
            }
        p->next = t;
        return head;
        }
};
