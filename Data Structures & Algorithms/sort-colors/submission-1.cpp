class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() , i = 0;
        while (i < n){
            bool ranWhile = false;
            int m = i;
            while (m < n-1 and nums[m] > nums[m+1]){
                ranWhile=true;
                swap(nums[m],nums[m+1]);
                m++;
            }
            while (m>0 and nums[m-1] > nums[m]){
                ranWhile=true;
                swap(nums[m],nums[m-1]);
                m--;
            }
            if (ranWhile) continue; 
            i++;
        }
    }
};