const int MAXN = 10010;
int trie[MAXN][128], tot;
int flag[MAXN], tots;
int idx[MAXN];
int f[MAXN];
class Solution {
public:
    int insert(const string& s) {
        int now = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!trie[now][s[i]]) {
                tot++;
                memset(trie[tot], 0, sizeof(trie[tot]));
                flag[tot] = 0;
                trie[now][s[i]] = tot;
            }
            now = trie[now][s[i]];
        }
        if(!flag[now])
            flag[now] = ++tots;
        return flag[now];
    }

    void buildAC() {
        queue<int> que;
        for(int i = 0; i < 128; i++) {
            if(trie[0][i]) {
                que.push(trie[0][i]);
                f[trie[0][i]] = 0;
            }
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(int i = 0; i < 128; i++) {
                if(trie[u][i]) {
                    int v = trie[u][i];
                    que.push(v);
                    f[v] = trie[f[u]][i];
                } else {
                    trie[u][i] = trie[f[u]][i];
                }
            }
        }
    }

    int limit[MAXN], cmpToLimit[MAXN];
    vector<int> v[MAXN];
    vector<int> findSubstring(string s, vector<string>& words) {
        tot = 0;
        memset(trie[0], 0, sizeof(trie[0]));
        flag[0] = 0;
        tots = 0;

        for(int i = 0; i < words.size(); i++) {
            idx[i] = insert(words[i]);
        }
        buildAC();

        for(int i = 0; i <= tots; i++) {
            limit[i] = 0;
            cmpToLimit[i] = 0;
        }
        for(int i = 0; i < words.size(); i++) {
            limit[idx[i]]++;
        }

        int now = 0;
        int wordslen = words[0].size();
        for(int i = 0; i < wordslen; i++) {
            v[i].clear();
        }
        for(int i = 0; i < s.size(); i++) {
            now = trie[now][s[i]];
            v[i % wordslen].push_back(flag[now]);
        }

        int bThanLimit = 0;
        vector<int> ret;
        for(int i = 0; i < wordslen; i++) {
            for(int j = 0; j < v[i].size(); j++) {
                int x = v[i][j];
                if(cmpToLimit[x] == limit[x])
                    bThanLimit++;
                cmpToLimit[x]++;

                if(j >= words.size()) {
                    int y = v[i][j - words.size()];
                    if(cmpToLimit[y] == limit[y] + 1)
                        bThanLimit--;
                    cmpToLimit[y]--;
                }
                if(0 == bThanLimit && j + 1 >= words.size()) {
                    ret.push_back(j * wordslen + i - words.size() * wordslen + 1);
                }
            }
            bThanLimit = 0;
            for(int j = max(0, (int)v[i].size() - (int)words.size()); j < v[i].size(); j++) {
                int x = v[i][j];
                cmpToLimit[x] = 0;
            }
        }
        return ret;
    }
};