class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = (nums.size() > 0), loc = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                nums[loc++] = nums[i];
                ret++;
            }
        }
        return ret;
    }
};