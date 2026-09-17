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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* fake = new ListNode(1);
        ListNode* newHead = fake;
        while(l1 || l2){
            int a = 0, b = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }
            fake->next = new ListNode((a + b + carry)%10);
            fake = fake->next;
            carry = (a + b + carry)/10;
        }

        if(carry){
            fake->next = new ListNode(carry);
        }
        ListNode* ans = newHead->next;
        delete newHead;

        
        return ans;
    }
};
