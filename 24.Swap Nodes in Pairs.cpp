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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) 
        return head;
        ListNode *p1=head,*p2=head->next,*p3=p2->next;
        head=p2;
        int flag=0;
        while(p3!=NULL)
        {
            p2->next=p1;
            p1->next=p3->next;
            p2=p1->next;
            
            if(p2!=NULL)
            {
                p1=p3;
                p3=p2->next;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            p2->next=p1;
            p1->next=p3;
        }
        else
        {
            p1->next=p3;
        }
        return head;
    }
};
