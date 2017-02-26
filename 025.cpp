class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int K) {
        ListNode *p = head;
        int cc = 0;
        for(cc = 0; cc < K && p != NULL; cc++, p = p -> next);
        if(cc < K)
            return head;
        ListNode *q = p, *dummyNode = new ListNode(-1), *pre = dummyNode;
        p = head;
        while(p != NULL) {
            ListNode *pp = p;
            for(int i = 0; i < K; i++) {
                ListNode *tmp = p -> next;
                p -> next = pre -> next;
                pre -> next = p;
                p = tmp;
            }
            pp -> next = q;
            pre = pp;
            p = q;
            int cc = 0;
            for(cc = 0; cc < K && q != NULL; cc++, q = q -> next);
            if(cc < K)
                break;
        }
        ListNode *ret = dummyNode -> next;
        delete dummyNode;
        return ret;
    }
};