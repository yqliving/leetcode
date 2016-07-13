class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string> & strs) {
        unordered_map <string, vector<string>> count;
        int i = 0;
        for (auto s : strs) {
            sort(s.begin(), s.end());
            count[s].push_back(strs[i++]);
        }
        vector<vector<string>> res;
        for (auto c : count) {
            sort(c.second.begin(), c.second.end());  // output from a-z
            res.push_back(n.second);
        }
        return res;
    }
};


//map like hash table
// s extract an element in strs every
// count first [abc] second:"abc","cab"...
//             [efr]       :"erf","rfe"...
