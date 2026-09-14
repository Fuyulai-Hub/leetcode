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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* d=new ListNode(0);
        d->next=head;
        ListNode* pre=d;
        for(int i=0;i<left-1;i++){
            pre=pre->next;
        }
        ListNode*c=pre->next;
        for(int i=0;i<right-left;i++){
            ListNode*t=c->next;//指向下一个节点
            c->next=t->next;//跳过下一个节点
            t->next=pre->next;//
            pre->next=t;//指向前一个节点
        }
        ListNode*r=d->next;
        delete d;
        return r;
    }
};
