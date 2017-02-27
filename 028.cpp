class Solution {
public:
    int strStr(string haystack, string needle) {
        int ret = -1;
        for(int i = 0; i + needle.size() <= haystack.size(); i++) {
            bool judge = true;
            for(int j = 0; j < needle.size(); j++) {
                if(haystack[i + j] != needle[j]) {
                    judge = false;
                    break;
                }
            }
            if(judge)
                return i;
        }
        return ret;
    }
};