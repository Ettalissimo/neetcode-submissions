class Solution {
public:
    bool helper(vector<int>& nums, int target, int first, int last){
        int m = (first+last)/2;
        int row = 0;
        bool val = true;
        if(first > last){
            return !val;
        };
        if (nums[m] < target){
            first = m + 1;
            row = first;
            return helper(nums,target,first,last);
        } else if (nums[m] > target) {
            last = m-1;
            return helper(nums,target,first,last);
        } else {
            return val;
        }
    }
    bool search(vector<int>& nums, int target) {
        int first = 0 , last = nums.size() - 1;
        return helper(nums, target, first, last);
    }

    bool search_row(vector<vector<int>>& matrix,vector<int> nums, int target, int first, int last){

        int m = (first+last)/2;
        if(first > last){
            return false;
        };
        if (target == nums[m]){
            return true;
        }
        if(nums[last] < target){
            return search(matrix[last],target);
        } else if(nums[m] < target and nums[m+1] > target){
            return search(matrix[m],target);            
        } else if (nums[m] > target){
            return search_row(matrix,nums,target,first,m - 1);
        } else {
            return search_row(matrix,nums,target,m + 1,last);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search on first element of each row once found the right one bfs on the row
        int s_row = matrix.size();

        vector<int> first_c ;
        for (int i=0; i < s_row; i++){
            first_c.push_back(matrix[i][0]);
        }
        auto res_row = search_row(matrix,first_c,target,0,matrix.size() - 1);
        return res_row;
    }
};
