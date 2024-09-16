class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
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
                    ans = min(ans, prevIndex);
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