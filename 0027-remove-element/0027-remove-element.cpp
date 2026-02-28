// best solution if order does NOT matter

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
        while(k<n){
            if(nums[k] == val){
                nums[k] = nums[n-1];
                n--;
            }
            else k++;
        }

        return n;
    }
};



// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int k=0;
//         for (int i=0; i<nums.size(); i++){
//             if(nums[i] != val){
//                 nums[k] = nums[i];
//                 k++;
//             }
//         }

//         return k;
        
//     }
// };