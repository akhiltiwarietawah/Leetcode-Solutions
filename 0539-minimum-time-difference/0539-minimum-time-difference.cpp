class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Optimization macros
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma") // Enable vectorization instructions (if supported by your machine)

    // Shortcuts for common data types
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> pii;

    // Fast input/output
    #define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #define pb push_back
    #define all(v) v.begin(), v.end()
        vector<bool> minutes(1440, false);

        for(string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            int min = 60*h + m ;
            if (minutes[min]) return 0;
            minutes[min] = true;
        }  

        int prevIndex = INT_MAX;
        int firstIndex = INT_MAX;
        int lastIndex = INT_MAX;
        int ans = INT_MAX;

        for(int i = 0; i < 1440; i++) {
            if(minutes[i]) {
                if(prevIndex != INT_MAX) {
                    ans = min(ans,i - prevIndex);
                }
                prevIndex = i;
                if(firstIndex == INT_MAX) {
                    firstIndex = i;
                }
                lastIndex = i;

            }
        }
         
         return min(ans,1440 - lastIndex + firstIndex);
    
    }
};

// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         vector<int> minutes(timePoints.size());

//         for(int i = 0; i < timePoints.size(); i++) {
//             string time = timePoints[i];
//             int h = stoi(time.substr(0, 2));
//             int m = stoi(time.substr(3));
//             minutes[i] = 60*h + m;
//         }

//         sort(minutes.begin(), minutes.end());

//         int ans = INT_MAX;

//         for(int i = 0; i < minutes.size() - 1; i++) {
//             ans = min(ans, minutes[i+1] - minutes[i]);
//         }

//         return min(ans, 24*60  + minutes[0] - minutes[minutes.size() - 1]);
//     }
// };