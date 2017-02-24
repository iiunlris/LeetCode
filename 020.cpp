class Solution {
public:
    char rev[300];
    bool isValid(string s) {
        stack<char> sta;
        rev['('] = ')';
        rev[')'] = '(';
        rev['['] = ']';
        rev[']'] = '[';
        rev['{'] = '}';
        rev['}'] = '{';

        for(int i = 0; i < s.size(); i++) {
            assert(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}');
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            }
            else {
                if(sta.empty())return false;
                char c = sta.top();
                sta.pop();
                if(c != rev[s[i]])
                    return false;
            }
        }
        if(!sta.empty())
            return false;
        return true;
    }
};