class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        vector<string> ans;
        
        // Use stringstream to easily split both s1 and s2 by spaces
        stringstream ss(s1 + " " + s2); // concatenate s1 and s2 with a space
        string word;

        // Parse words from the combined string and update frequency in the map
        while (ss >> word) {
            mpp[word]++;
        }

        // Collect words that appear exactly once
        for (const auto& it : mpp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
