class Solution {
public:
    void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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

    void merge_2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0 ; i < n ; ++i){
            nums1[m + i] = nums2[i];
        }
        if (m == 0 or n ==0){
            return;
        }
        if (nums1[m-1] < nums1[m]){
            return;
        }
        sort(nums1.begin(),nums1.end());
        return;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = n + m - 1;
        int i = n-1 , j = m-1;
        while(i >= 0 and j >= 0){
            if( nums1[j] < nums2[i]){
                nums1[last] = nums2[i];
                i--; 
            }
            else{
                nums1[last] = nums1[j];
                j--; 
            }
            last--;
        }
        while(i >= 0){
            nums1[last] = nums2[i ];
            i--; last--;
        }
        return;
    }




};