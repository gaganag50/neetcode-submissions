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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using pil = pair<int, ListNode*>;
        priority_queue<pil, vector<pil>, greater<pil>> pq;
        int n = lists.size();
        for(int i = 0; i < n; ++i) {
            ListNode* ptr = lists[i];
            if(ptr)
                pq.push({ptr->val, ptr});
        }
        ListNode* fake = new ListNode(-1);
        ListNode* head = fake;
        while(!pq.empty()) {

            ListNode* ptr = pq.top().second;
            pq.pop();
            fake->next = ptr;
            ptr = ptr->next;
            if(ptr)
                pq.push({ptr->val, ptr});
            fake = fake->next;

        }
        return head->next;
    }
};
