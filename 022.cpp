class Solution {
public:
    vector<string> ret;
    void dfs(int x, int y, string now) {
        if(x) {
            dfs(x - 1, y, now + '(');
            if(x < y)
                dfs(x, y - 1, now + ')');
        } else if(y){
            dfs(x, y - 1, now + ')');
        } else {
            ret.push_back(now);
        }
    }
    vector<string> generateParenthesis(int n) {
        ret.clear();
        dfs(n, n, "");
        return ret;
    }
};