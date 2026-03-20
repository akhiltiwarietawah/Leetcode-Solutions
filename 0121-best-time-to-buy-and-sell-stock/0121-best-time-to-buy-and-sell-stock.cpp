#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(__builtin_expect(n < 2, 0)) return 0;
        
        const int* __restrict__ p = prices.data();
        int mini = p[0];
        int maxP = 0;

        for(int i = 1; i < n; ++i){
            int d = p[i] - mini;
            if(d > maxP) maxP = d;
            if(p[i] < mini) mini = p[i];
        }
        return maxP;
    }
};