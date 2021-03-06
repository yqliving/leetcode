//dfs，必须深度搜索才能判断其合理性
//time complexity O(n^4), space complexity O(n)
class Solution {
    public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, ip; //存放中间结果
        dfs(s, ip, res, 0);
        return res;
    }
    
    void dfs(string s, vector<string>& ip, vector<string>& res, int start) {
        if (ip.size() == 4 && start == s.size()) {          //一个符合条件的解
            res.push_back(ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3]);
            return;
        }
        if (s.size() - start > (4 - ip.size()) * 3) return;
        if (s.size() - start < (4 - ip.size())) return;
        
        int num = 0;
        for (int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if (num < 0 || num > 255) continue;
            ip.push_back(s.substr(start, i - start + 1));
            dfs(s, ip, res, i + 1);
            ip.pop_back();
            if (num == 0) break;       //前缀不能为0
        }
    }
};

/*
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> cur(4), prev(4);
        cur[0].push_back(s.substr(0,1));
        for (int i = 1; i < s.size(); ++i) {
            swap(cur, prev);
            for (int p = 0; p < 4; ++p) {
                cur[p].clear();
                if (p > 0) {
                    for (auto& str : prev[p - 1]) {
                        cur[p].push_back(str + "." + s[i]);
                    }
                }
                for (auto str : prev[p]) {
                    str += s[i];
                    auto pos = str.rfind('.');
                    int last = stoi(str.substr(pos + 1));
                    if (str[pos + 1] != '0' && last <= 255)
                        cur[p].push_back(str);
                }                
            }
        }
        return cur[3];
    }
};