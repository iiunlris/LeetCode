class Solution {
public:
    void del(ListNode *p) {
        if(p == NULL)
            return;
        del(p -> next);
        delete p;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = new ListNode(-1);
        ListNode *head = p;
        while(l1 != NULL || l2 != NULL) {
            if(l1 == NULL || (l2 != NULL && l2 -> val <= l1 -> val)) {
                p -> next = l2;
                l2 = l2 -> next;
            }
            else{
                p -> next = l1;
                l1 = l1 -> next;
            }
            p = p -> next;
        }
        del(l1);
        del(l2);
        ListNode *ret = head -> next;
        delete head;
        return ret;
    }
};