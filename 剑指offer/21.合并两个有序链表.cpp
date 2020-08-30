/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l1 != nullptr && l2 != nullptr){
          if(l1->val < l2->val){
            p->next = l1;
            p = p->next;
            l1 = l1->next;
          }else{
            p->next = l2;
            p = p->next;
            l2 = l2->next;
          }
        }
      if(l1 == nullptr){
        p->next = l2;
        p = p->next;
      }
      if(l2 == nullptr){
        p->next = l1;
        p = p->next;
      }
      return head->next;
    }
};
