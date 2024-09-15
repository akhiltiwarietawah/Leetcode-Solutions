class Solution {
private:
    int vowelBitmask(char c) {
        if (c == 'a')
            return 1; // 00001
        if (c == 'e')
            return 2; // 00010
        if (c == 'i')
            return 4; // 00100
        if (c == 'o')
            return 8; // 01000
        if (c == 'u')
            return 16; // 10000
        return 0;      // Non-vowel characters return 0
    }

public:
    int findTheLongestSubstring(string s) {

        int prefixXor = 0;

        int ans = 0;
        // Hash map to store the first occurrence of each prefixXor state
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // Initialize with -1 to handle full valid substrings from the start

        for (size_t i = 0; i < s.length(); ++i) {
            prefixXor ^= vowelBitmask(s[i]);

            // If we've seen this prefixXor before, calculate the length of the
            // substring
            if (prefixMap.find(prefixXor) != prefixMap.end()) {
                ans = max(ans, static_cast<int>(i - prefixMap[prefixXor]));
            } 
            else {
                // If it's the first time we've seen this prefixXor, store the
                // index
                prefixMap[prefixXor] = i;
            }
        }

        return ans;
    }
};