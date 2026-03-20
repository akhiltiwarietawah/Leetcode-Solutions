class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int h) {
        
        const int n = grid.size();      // rows
        const int m = grid[0].size();   // cols

        // Result matrix banao (m-h+1) x (n-h+1) size ka
        std::vector<std::vector<int>> arr(n - h + 1,
                                          std::vector<int>(m - h + 1));

        // ⭐ KEY OPTIMIZATION — ek baar memory reserve karo
        std::vector<int> v;
        v.reserve(h * h);  // k*k = max elements jo submatrix mein ho sakte hain

        for (int i = 0; i < n - h + 1; ++i) {
            for (int j = 0; j < m - h + 1; ++j) {

                // Submatrix ke elements collect karo
                for (int k = i; k < i + h; ++k) {
                    for (int l = j; l < j + h; ++l) {
                        v.push_back(grid[k][l]);
                    }
                }

                if (v.size() > 1) {  // k=1 ka edge case handle
                    
                    std::sort(v.begin(), v.end());  // sort karo

                    int min = std::numeric_limits<int>::max();  // INT_MAX
                    int x = 0;

                    while (x < v.size() - 1) {
                        if (v[x] != v[x + 1]) {  // duplicates skip karo
                            min = std::min(min, v[x + 1] - v[x]);
                        }
                        x++;
                    }

                    // Agar min change nahi hua → saare same values
                    arr[i][j] = (min == std::numeric_limits<int>::max()) ? 0 : min;

                } else {
                    arr[i][j] = 0;  // sirf ek element → diff = 0
                }

                // ⭐ KEY OPTIMIZATION — memory free nahi hoti, sirf size = 0
                v.resize(0);
            }
        }

        return arr;
    }
};