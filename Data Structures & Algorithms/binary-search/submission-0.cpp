class Solution {
public:
    int helper(vector<int>& nums, int target, int first, int last){
        int m = (first+last)/2;
        if(first > last){
            return -1;
        };
        if (nums[m] < target){
            first = m + 1;
            return helper(nums,target,first,last);
        } else if (nums[m] > target) {
            last = m-1;
            return helper(nums,target,first,last);
        } else {
            return m;
        }
    }
    int search(vector<int>& nums, int target) {
        int first = 0 , last = nums.size() - 1;
        return helper(nums, target, first, last);
    }
};
