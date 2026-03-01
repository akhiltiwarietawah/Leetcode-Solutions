//first method with extra space O(n) nd tc == O(n)

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;
//         vector<int> temp(n);
//         for(int i = 0; i < n; i++){
//             temp[(i+k)%n] = nums[i];
//         }
//         nums = temp;
//     }
// };




// Method 2 using Cyclic replacement
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;
        for(int start = 0; count < n; start++){
            int current = start;
            int prev = nums[start];

            do{
                int next = (current + k)%n;
                int temp =  nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(start != current);
        }
    }
};