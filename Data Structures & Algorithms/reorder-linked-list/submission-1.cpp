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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        // 2 4
        // 8 6
        ListNode* fake = new ListNode(0);
        ListNode* newHead = fake;
        bool isFirst = true;
        while(list1 || list2) {
            if(isFirst){
                newHead->next = list1;
                list1 = list1->next;
            } else {
                newHead->next = list2;
                list2 = list2->next;
            }
            newHead = newHead->next;
            isFirst = !isFirst;
        }
        return fake->next;
    }

public:
    void reorderList(ListNode* head) {
        if(!head)return;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = NULL;
        second = reverseList(second);
        head = merge(first, second);

    }
};
