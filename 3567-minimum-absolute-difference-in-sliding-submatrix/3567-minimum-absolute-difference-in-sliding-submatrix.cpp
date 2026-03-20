class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int rows = m - k + 1;
        int cols = n - k + 1;
        
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                // k x k submatrix ke saare values collect karo
                vector<int> values;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        values.push_back(grid[r][c]);
                    }
                }
                
                // Sort karo
                sort(values.begin(), values.end());
                
                int minDiff = INT_MAX;
                int prev = values[0];
                
                for (int idx = 1; idx < (int)values.size(); idx++) {
                    if (values[idx] != prev) {
                        minDiff = min(minDiff, values[idx] - prev);
                        prev = values[idx];
                    }
                }
                
                // Agar saare values same hain toh 0, warna minDiff
                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        
        return ans;
    }
};