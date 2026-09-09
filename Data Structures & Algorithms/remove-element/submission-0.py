class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        count, i, j = 0, 0, n-1
        while i <= j :
            if nums[j] == val :
                j = j - 1
                count = count + 1
            elif (nums[i] == val and nums[j] != val) : 
                nums[i] = nums[j]
                nums[j] = 101
                i = i + 1
                j = j - 1
                count = count + 1
            else: 
                i = i + 1
        
        return n - count