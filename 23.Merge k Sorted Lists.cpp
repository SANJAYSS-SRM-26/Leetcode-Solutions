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
 struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;
        if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size();i++) if(lists[i]!=NULL) pq.push(lists[i]);
        if(pq.empty()) return NULL;
        ListNode* k = new ListNode(0);
        ListNode * l = k;
        while(!pq.empty()){
            ListNode* tmp = pq.top();
            l->next = tmp;
            l = l->next;
            pq.pop();
            if(tmp->next!=NULL) pq.push(tmp->next);   
        }
        return k->next;

    }
};
