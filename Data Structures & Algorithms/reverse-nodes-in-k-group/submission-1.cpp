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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return NULL;
        ListNode* curr = head, *prev = NULL;
        int cnt = k;
        while(k-- && curr){
            prev = curr;
            curr = curr->next;
        }

        if(k >= 0) return head;


        prev->next = NULL;

        ListNode* newHead = reverseList(head);
        head->next = reverseKGroup(curr,cnt);
        return newHead;
    }
};
