class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int k=1;

        for(int i=1; i < nums.size(); i++){
            if(nums[i] != nums[k-1]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};