class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0 ; i < n ; ++i){
            nums1[m + i] = nums2[i];
        }
        if (m == 0 or n ==0){
            return;
        }
        if (nums1[m-1] < nums1[m]){
            return;
        }
        for (int i = m ; i < m+n ; ++i){
            int j = i-1;
            while( j>=0 and nums1[j+1] < nums1[j] ){
                swap(nums1[j],nums1[j+1]);
                j--;
            }
        }
        return;
    }
};