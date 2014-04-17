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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *h, *t;
        h = t = NULL;
        
        while (head != NULL) {
            ListNode *last = NULL;
            ListNode *min = head;
            ListNode *cur = head;
            while (cur->next != NULL) {
                if (cur->next->val < min->val) {
                    last = cur;
                    min = cur->next;
                }
                cur = cur->next;
            }
            if (h == NULL) {
                h = t = min;
            } else {
                t->next = min;
                t = min;
            }
            
            if (min == head) {
                head = head->next;
            } else {
                last->next = min->next;
            }
        }
        if (t != NULL) {
            t->next = NULL;
        }
        return h;
    }
};
