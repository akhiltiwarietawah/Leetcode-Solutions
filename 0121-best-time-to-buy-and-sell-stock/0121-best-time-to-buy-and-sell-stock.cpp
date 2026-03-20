class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n < 2) return 0;  // early exit

        // raw pointer — vector bounds check skip
        const int* p = prices.data();
        
        int mini = p[0];
        int maxP = 0;
        int diff;

        for(int i = 1; i < n; ++i){
            diff = p[i] - mini;
            
            // Branchless — no if/else
            // Branch misprediction avoid karo
            maxP = maxP ^ ((diff ^ maxP) & -(diff > maxP));
            mini = mini ^ ((p[i] ^ mini) & -(p[i] < mini));
        }
        return maxP;
    }
};