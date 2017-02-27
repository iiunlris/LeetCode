class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;
        for(int v: nums) {
            if(v ^ val)
                nums[ret++] = v;
        }
        return ret;
    }
};
