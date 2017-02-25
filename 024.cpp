class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(-1), *p = head, *q = dummyNode;
        while(p != NULL) {
            ListNode *a = p, *b = NULL;
            p = p -> next;
            if(p != NULL) {
                b = p;
                p = p -> next;
            }

            if(b != NULL) {
                q -> next = b;
                q = q -> next;
            }
            q -> next = a;
            q = q -> next;
        }
        q -> next = NULL;
        ListNode *ret = dummyNode -> next;
        delete dummyNode;
        return ret;
    }
};