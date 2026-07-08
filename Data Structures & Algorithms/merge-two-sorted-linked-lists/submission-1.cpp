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
        ListNode* ptr, *fake = new ListNode(-1);
        ptr = fake;
        while(list1 && list2) {
            int a = list1->val;
            int b = list2->val;
            if(a < b){
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1){
            ptr->next = list1;
        } else if(list2){
            ptr->next = list2;
        }
        return fake->next;
    }
};
