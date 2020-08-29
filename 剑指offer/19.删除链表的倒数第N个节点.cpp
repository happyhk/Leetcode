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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0);
      ListNode* fast = dummy;
      ListNode* end = dummy;
      dummy->next = head;
      for(int i = 1; i <= n+1; ++i) {
        fast = fast->next;
      }
      
      while(fast) {
        fast = fast->next;
        end = end->next;
      }

      end->next = end->next->next;
      end = end->next;
      return dummy->next;





        
    }
};
