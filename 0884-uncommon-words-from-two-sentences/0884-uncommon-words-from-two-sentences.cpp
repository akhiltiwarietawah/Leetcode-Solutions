class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;

        vector<string> ans;

        string s = "";

        for(auto ch : s1) {
            if(ch == ' ') {
                mpp[s]++;
                s = "";
            }
            else s += ch;
        }

        mpp[s]++;
        s = "";

        for(auto ch : s2) {
            if(ch == ' ') {
                mpp[s]++;
                s = "";
            }
            else s += ch;
        }
        mpp[s]++;

        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};