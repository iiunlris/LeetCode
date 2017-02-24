class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n >= 0);
        if(0 == n)
            return head;
        n--;

        ListNode *p = head;
        for(int i = 0; i < n; i++) {
            assert(p -> next != NULL);
            p = p -> next;
        }

        ListNode *q = head, *qpre = NULL;
        while(p -> next != NULL) {
            p = p -> next;
            qpre = q;
            q = q -> next;
        }

        if(qpre == NULL) {
            ListNode *ret = q -> next;
            delete q;
            return ret;
        }
        else {
            qpre -> next = q -> next;
            delete q;
            return head;
        }
    }
};