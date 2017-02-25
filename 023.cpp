struct Re {
    int val, idx;
    Re() {
    }
    Re(int val, int idx):val(val), idx(idx) {
    }
    bool operator< (const Re& re)const {
        return val > re.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Re> que;
        ListNode *dummyNode = new ListNode(-1), *p = dummyNode;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL)
                que.push(Re(lists[i] -> val, i));
        }

        while(!que.empty()) {
            Re u = que.top();
            que.pop();
            p -> next = lists[u.idx];
            p = p -> next;
            if(lists[u.idx] -> next != NULL) {
                lists[u.idx] = lists[u.idx] -> next;
                que.push(Re(lists[u.idx] -> val, u.idx));
            }
        }

        ListNode* ret = dummyNode -> next;
        delete dummyNode;
        return ret;
    }
};