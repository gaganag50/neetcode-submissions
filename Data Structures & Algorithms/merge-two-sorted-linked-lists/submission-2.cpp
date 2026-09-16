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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fake = new ListNode(0);
        ListNode* newHead = fake;
        while(list1 || list2) {
            int a = INT_MAX, b = INT_MAX;
            if(list1) {
                a = list1->val;
            }
            if(list2) {
                b = list2->val;
            }
            if(a < b){
                newHead->next = list1;
                list1 = list1->next;
            } else {
                newHead->next = list2;
                list2 = list2->next;
            }
            newHead = newHead->next;
        }
        return fake->next;
    }
};
